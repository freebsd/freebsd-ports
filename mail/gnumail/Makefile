# New ports collection makefile for:    GNUMail
# Date created:         11 Jun 2001
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnumail
PORTVERSION=	1.0.3
CATEGORIES=	mail
MASTER_SITES=	http://www.collaboration-world.com/mirror/ \
		http://extrovert.screwdriver.net/~extra/
DISTNAME=	GNUMail-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org

BUILD_DEPENDS=	${XGPSBUNDLEDIR}/${GNU_ARCH}/${OPSYS:L}/gnu-gnu-gnu/libgnustep-xgps:${PORTSDIR}/x11-toolkits/gnustep-xgps \
		${LOCALLIBDIR}/${GNU_ARCH}/${OPSYS:L}/gnu-gnu-gnu/libPantomime.so:${PORTSDIR}/mail/pantomime
RUN_DEPENDS=	${XGPSBUNDLEDIR}/${GNU_ARCH}/${OPSYS:L}/gnu-gnu-gnu/libgnustep-xgps:${PORTSDIR}/x11-toolkits/gnustep-xgps \
		${LOCALLIBDIR}/${GNU_ARCH}/${OPSYS:L}/gnu-gnu-gnu/libPantomime.so:${PORTSDIR}/mail/pantomime

PREFIX=		${LOCALBASE}/GNUstep
WRKSRC=		${WRKDIR}/GNUMail
USE_GMAKE=	yes
MAKEFILE=
MAKE_FLAGS=	GUI_BACKEND_LIB=xgps
ALL_TARGET=
NO_MTREE=	yes

XGPSBUNDLEDIR=	${PREFIX}/System/Library/Bundles/libgnustep-xgps.bundle
LOCALLIBDIR=	${PREFIX}/Local/Libraries

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} == "i386"
GNU_ARCH=	ix86
.else
GNU_ARCH=	${MACHINE_ARCH}
.endif

PLIST_SUB+=	GNU_ARCH=${GNU_ARCH} OPSYS=${OPSYS:L}

do-build:
	@(cd ${WRKSRC}; . ${PREFIX}/System/Makefiles/GNUstep.sh; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${ALL_TARGET})

do-install:
	@(cd ${WRKSRC}; . ${PREFIX}/System/Makefiles/GNUstep.sh; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})

.include <bsd.port.post.mk>
