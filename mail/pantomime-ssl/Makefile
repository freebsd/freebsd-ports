# New ports collection makefile for:    Pantomime-SSL
# Date created:				27.October 2002
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	pantomime
PORTVERSION=	1.0.5
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.collaboration-world.com/pantomime.data/releases/Stable/ \
		ftp://ftp.gnustep.org/pub/gnustep/libs/
PKGNAMESUFFIX=	-ssl
DISTNAME=	Pantomime-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	SSL Connections for pantomime

BUILD_DEPENDS+=	${LOCALLIBDIR}/libPantomime.so:${PORTSDIR}/${PANTOMIME_PORT}
RUN_DEPENDS+=	${LOCALLIBDIR}/libPantomime.so:${PORTSDIR}/${PANTOMIME_PORT}

PREFIX=		${LOCALBASE}/GNUstep
NO_MTREE=	yes
WRKSRC=		${WRKDIR}/Pantomime/Bundles/SSL
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile

.include <bsd.port.pre.mk>

.include "${PORTSDIR}/security/openssl/bsd.openssl.mk"

USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
.include "${PORTSDIR}/devel/gnustep/bsd.gnustep.mk"

PANTOMIME_PORT?=	mail/pantomime

.include <bsd.port.post.mk>
