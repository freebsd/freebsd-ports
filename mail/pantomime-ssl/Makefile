# New ports collection makefile for:    Pantomime-SSL
# Date created:				27.October 2002
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	pantomime
PORTVERSION=	1.0.5
CATEGORIES=	mail
MASTER_SITES=	http://extrovert.screwdriver.net/~extra/ \
		ftp://ftp.gnustep.org/pub/gnustep/libs/
PKGNAMESUFFIX=	-ssl
DISTNAME=	Pantomime-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org

BUILD_DEPENDS+=	${LOCALLIBDIR}/libPantomime.so:${PORTSDIR}/mail/pantomime
RUN_DEPENDS+=	${LOCALLIBDIR}/libPantomime.so:${PORTSDIR}/mail/pantomime

PREFIX=		${LOCALBASE}/GNUstep
WRKSRC=		${WRKDIR}/Pantomime/Bundles/SSL
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
ALL_TARGET=
NO_MTREE=	yes
LOCALLIBDIR=	${PREFIX}/Local/Libraries/${GNU_ARCH}/${OPSYS:L}/gnu-gnu-gnu

.include <bsd.port.pre.mk>

.include "${PORTSDIR}/security/openssl/Makefile.ssl"

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
