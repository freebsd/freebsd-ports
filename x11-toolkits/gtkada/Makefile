# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtkada
PORTVERSION=	2.24.4.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://downloads.dragonlace.net/src/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		gtkada-rm-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Ada graphical toolkit based on Gtk2+

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_PERL5=	build
USE_GNOME=	gtk20
NO_MTREE=	yes
USES=		ada gmake perl5 pkgconfig

MAKE_ENV+=	PROCESSORS=${MAKE_JOBS_NUMBER}

NO_LICENSES_INSTALL= yes

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
#	This target is recreated because -j cannot be set, but
#	MAKE_JOBS_SAFE=yes is needed for PROCESSORS value
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} all

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libdata
	@${MV} ${STAGEDIR}${PREFIX}/lib/pkgconfig ${STAGEDIR}${PREFIX}/libdata/
	${RM} -rf ${STAGEDIR}${PREFIX}/share/doc/gtkada/gtkada_ug/_sources
	@cd ${STAGEDIR}${PREFIX}; ${FIND} * \( -type f -or -type l \) | \
	   ${SORT} > ${TMPPLIST}
	@cd ${STAGEDIR}${PREFIX}; ${FIND} * -type d | ${AWK} '/\//' | ${SORT} -r | \
	   ${SED} -e '/lib\/gnat$$/d' -e '/share\/doc$$/d' -e '/share\/gps/d' \
	   -e '/share\/examples$$/d' -e '/libdata\/pkgconfig/d' \
	   -e 's/^/@dirrm /g' >> ${TMPPLIST}
	@echo "@unexec rmdir %D/lib/gnat 2>/dev/null || true" >> ${TMPPLIST}
	@echo "@unexec rmdir %D/libdata/pkgconfig 2>/dev/null || true" >> ${TMPPLIST}
	@echo "@unexec rmdir %D/share/gps/plug-ins 2>/dev/null || true" >> ${TMPPLIST}
	@echo "@unexec rmdir %D/share/gps 2>/dev/null || true" >> ${TMPPLIST}
	@echo "@unexec rmdir %D/share/examples 2>/dev/null || true" >> ${TMPPLIST}
	@echo "@unexec rmdir %D/share/doc 2>/dev/null || true" >> ${TMPPLIST}

.include <bsd.port.mk>
