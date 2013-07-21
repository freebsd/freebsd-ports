# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtkada
PORTVERSION=	2.24.4.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://downloads.dragonlace.net/src/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		gtkada-rm-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Ada graphical toolkit based on Gtk2+

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_PERL5_BUILD=yes
USE_GNOME=	gtk20
USES=		ada gmake

DESTINY=	${WRKDIR}/destino
MAKE_ENV+=	DESTDIR=${DESTINY} \
		PROCESSORS=${MAKE_JOBS_NUMBER}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	sphinx-build:${PORTSDIR}/textproc/py-sphinx
.endif

.if ${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS+=	--enable-nls
USES+=			gettext
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

post-patch:
	@${REINPLACE_CMD} -e '/DESTDIR =/d' ${WRKSRC}/src/Makefile.common.in
.if ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's/^all: \(.*\)/all: \1 docs/g' ${WRKSRC}/Makefile.in
.endif

do-build:
	# This target is recreated because -j cannot be set, but
	# MAKE_JOBS_SAFE=yes is needed for PROCESSORS value
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} gmake all

post-install:
	@${MKDIR} ${DESTINY}${PREFIX}/libdata
	@${MV} ${DESTINY}${PREFIX}/lib/pkgconfig ${DESTINY}${PREFIX}/libdata/
	${RM} -rf ${DESTINY}${PREFIX}/share/doc/gtkada/gtkada_ug/_sources
	${CP} -pR ${DESTINY}${PREFIX}/ ${PREFIX}/
	@cd ${DESTINY}${PREFIX}; ${FIND} * \( -type f -or -type l \) | \
	   ${SORT} > ${WRKDIR}/PLIST.all
	@cd ${DESTINY}${PREFIX}; ${FIND} * -type d | ${AWK} '/\//' | ${SORT} -r | \
	   ${SED} -e '/lib\/gnat$$/d' -e '/share\/doc$$/d' -e '/share\/gps/d' \
	   -e '/share\/examples$$/d' -e '/libdata\/pkgconfig/d' \
	   -e 's/^/@dirrm /g' >> ${WRKDIR}/PLIST.all
	@echo "@unexec rmdir %D/lib/gnat 2>/dev/null || true" >> ${WRKDIR}/PLIST.all
	@echo "@unexec rmdir %D/libdata/pkgconfig 2>/dev/null || true" >> ${WRKDIR}/PLIST.all
	@echo "@unexec rmdir %D/share/gps/plug-ins 2>/dev/null || true" >> ${WRKDIR}/PLIST.all
	@echo "@unexec rmdir %D/share/gps 2>/dev/null || true" >> ${WRKDIR}/PLIST.all
	@echo "@unexec rmdir %D/share/examples 2>/dev/null || true" >> ${WRKDIR}/PLIST.all
	@echo "@unexec rmdir %D/share/doc 2>/dev/null || true" >> ${WRKDIR}/PLIST.all
	@${CAT} ${WRKDIR}/PLIST.all >> ${TMPPLIST}

.include <bsd.port.mk>
