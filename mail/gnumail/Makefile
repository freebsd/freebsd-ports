# New ports collection makefile for:    GNUMail
# Date created:         11 Jun 2001
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnumail
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.collaboration-world.com/gnumail.data/releases/Stable/ \
		ftp://ftp.gnustep.org/pub/gnustep/usr-apps/
DISTNAME=	GNUMail-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org

BUILD_DEPENDS=	${BACKBUNDLEDIR}/libgnustep-back:${PORTSDIR}/x11-toolkits/gnustep-back
BUILD_DEPENDS+=	${LOCALBASE}/lib/libcallback.a:${PORTSDIR}/devel/ffcall
BUILD_DEPENDS+=	${LOCALLIBDIR}/libPantomime.so:${PORTSDIR}/mail/pantomime
RUN_DEPENDS=	${BACKBUNDLEDIR}/libgnustep-back:${PORTSDIR}/x11-toolkits/gnustep-back
RUN_DEPENDS+=	${LOCALLIBDIR}/libPantomime.so:${PORTSDIR}/mail/pantomime

PREFIX=		${LOCALBASE}/GNUstep
WRKSRC=		${WRKDIR}/GNUMail
USE_GMAKE=	yes
MAKEFILE=
MAKE_FLAGS+=	GUI_BACKEND_LIB=back
ALL_TARGET=
NO_MTREE=	yes

BACKBUNDLEDIR=	${PREFIX}/System/Library/Bundles/libgnustep-back.bundle/${GNU_ARCH}/${OPSYS:L}/gnu-gnu-gnu
LOCALLIBDIR=	${PREFIX}/Local/Libraries/${GNU_ARCH}/${OPSYS:L}/gnu-gnu-gnu

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
