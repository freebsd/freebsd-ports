# New ports collection makefile for:	amaya
# Date created:		26 Dec 1998
# Whom:			Don Croyle <croyle@gelemna.org>
#
# $FreeBSD$
#

PORTNAME=	amaya
PORTVERSION=	6.4
CATEGORIES=	www
MASTER_SITES=	http://www.w3.org/Amaya/Distribution/ \
		ftp://ftp.w3.org/pub/amaya/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}
DISTFILES=	${DISTNAME}.tgz
DIST_SUBDIR=	amaya

MAINTAINER=	adam-ports@blacktabby.org

WRKSRC=		${WRKDIR}/Amaya/obj

USE_GNOMENG=	yes
USE_GNOME=	imlib
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-gtk --without-graphic-libs

DICT?=		none

.if ${DICT} != "none"
.if ${DICT} == "all"
DISTFILES+=	Dutch.tgz
DISTFILES+=	English.tgz
DISTFILES+=	French.tgz
DISTFILES+=	German.tgz
DISTFILES+=	Italian.tgz
DISTFILES+=	Spanish.tgz
DISTFILES+=	Swedish.tgz
.else
DISTFILES+=	${DICT:S/$/.tgz/g}
.endif
.endif

pre-everything::
.if ${DICT} == "none"
	@${ECHO_MSG} Several spellchecking dictionaries are available.  To use
	@${ECHO_MSG} one of them, define DICT to be the appropriate language.
.endif

post-extract:
	${MKDIR} ${WRKSRC}

post-patch:
	${REINPLACE_CMD} -e 's|\"1.0\\.|\"1\\.|g ; \
		 s|gtk-config --cflags|imlib-config --cflags-gdk|g ; \
		 s|gtk-config --libs|imlib-config --libs-gdk|g ; \
		 s| -lgdk_imlib||g' ${WRKSRC}/../configure

post-configure:
	${LN} -sf ${WRKSRC}/Options.orig ${WRKSRC}/Options

post-install:
	${INSTALL_DATA} ${WRKSRC}/../amaya/COPYRIGHT.html ${PREFIX}/Amaya/amaya
.if ${DICT} != "none"
	${INSTALL_DATA} ${WRKDIR}/*.dic ${PREFIX}/Amaya/dicopar
	${MV} ${TMPPLIST} ${TMPPLIST}.new
	cd ${WRKDIR} && ls -1 *.dic | \
		${SED} -e 's|^|Amaya/dicopar/|' > ${TMPPLIST}
	${CAT} ${TMPPLIST}.new >> ${TMPPLIST}
	${RM} ${TMPPLIST}.new
.endif

.include <bsd.port.mk>
