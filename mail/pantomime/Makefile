# New ports collection makefile for:    Pantomime
# Date created:         17 Sep 2001
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pantomime
PORTVERSION=	1.0.5
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.collaboration-world.com/pantomime.data/releases/Stable/ \
		ftp://ftp.gnustep.org/pub/gnustep/libs/
DISTNAME=	Pantomime-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Mail/MIME handling library for GNUstep

PREFIX=		${LOCALBASE}/GNUstep
NO_MTREE=	yes
WRKSRC=		${WRKDIR}/Pantomime
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
ALL_TARGET=
LDCONFIG_DIRS=	${LOCALLIBDIR}
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
.include "${PORTSDIR}/devel/gnustep/bsd.gnustep.mk"

.include <bsd.port.post.mk>
