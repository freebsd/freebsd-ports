# New ports collection makefile for:	amaya
# Date created:		26 Dec 1998
# Whom:			Don Croyle <croyle@gelemna.org>
#
# $FreeBSD$
#

PORTNAME=	amaya
PORTVERSION=	8.5
CATEGORIES=	www
MASTER_SITES=	http://www.w3.org/Amaya/Distribution/ \
		ftp://ftp.w3.org/pub/amaya/ \
		http://ftp.uni-koeln.de/www/amaya/ \
		http://public.planetmirror.com/pub/amaya/ \
		ftp://ftp.uni-koeln.de/WWW/amaya/ \
		http://gd.tuwien.ac.at/infosys/browsers/amaya/ \
		http://ftp.ntua.gr/pub/www/W3C/amaya/ \
		ftp://ftp.ntua.gr/pub/www/W3C/amaya/ \
		ftp://nic.funet.fi/index/WWW/W3/amaya/ \
		http://www.nic.funet.fi/index/WWW/W3/amaya/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	amaya

MAINTAINER=	adam-ports@blacktabby.org
COMMENT=	The W3C's testbed web editor/browser

WRKSRC=		${WRKDIR}/Amaya/obj

USE_GNOME=	gnometarget imlib
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LIBS="${LDFLAGS}"

CFLAGS+=	-fpermissive

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

DICT?=		none

.if ${DICT} != "none"
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
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

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		"Does not compile on alpha"
.endif

.if ${X_WINDOW_SYSTEM:L} != xfree86-3 && defined(WITH_OPENGL)
LIB_DEPENDS+=	gtkgl.5:${PORTSDIR}/x11-toolkits/gtkglarea
USE_GL=		yes
CONFIGURE_ARGS+=	--with-gl
CFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	-lcompat ${PTHREAD_LIBS}
.endif

pre-everything::
.if ${DICT} == "none"
	@${ECHO_MSG} Several spellchecking dictionaries are available.  To use
	@${ECHO_MSG} one of them, define DICT to be the appropriate language.
.endif

post-extract:
	@${MKDIR} ${WRKSRC}

post-patch:
	@${GREP} -lR "<malloc\.h>" ${WRKDIR} | ${XARGS} ${REINPLACE_CMD} -e \
		's|<malloc\.h>|<stdlib.h>|g'

post-install:
	${INSTALL_DATA} ${WRKSRC}/../amaya/COPYRIGHT.html ${PREFIX}/Amaya/amaya
.if ${DICT} != "none"
	${INSTALL_DATA} ${WRKDIR}/*.dic ${PREFIX}/Amaya/dicopar
	${MV} ${TMPPLIST} ${TMPPLIST}.new
	cd ${WRKDIR} && ${LS} -1 *.dic | \
		${SED} -e 's|^|Amaya/dicopar/|' > ${TMPPLIST}
	${CAT} ${TMPPLIST}.new >> ${TMPPLIST}
	${RM} ${TMPPLIST}.new
.endif

.include <bsd.port.post.mk>
