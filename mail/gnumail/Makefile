# New ports collection makefile for:    GNUMail
# Date created:         11 Jun 2001
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnumail
PORTVERSION=	1.0.3
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://www.collaboration-world.com/gnumail.data/releases/Stable/ \
		ftp://ftp.gnustep.org/pub/gnustep/usr-apps/
DISTNAME=	GNUMail-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GNUstep mail client

BUILD_DEPENDS+=	${LOCALLIBDIR}/libPantomime.so:${PORTSDIR}/${PANTOMIME_PORT}
RUN_DEPENDS+=	${LOCALLIBDIR}/libPantomime.so:${PORTSDIR}/${PANTOMIME_PORT}

PREFIX=		${LOCALBASE}/GNUstep
NO_MTREE=	yes
WRKSRC=		${WRKDIR}/GNUMail
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=
ALL_TARGET=

.include <bsd.port.pre.mk>

PANTOMIME_PORT?=	mail/pantomime

.include <bsd.port.post.mk>
