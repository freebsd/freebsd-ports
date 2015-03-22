# $FreeBSD$

PORTNAME=	easydiff
PORTVERSION=	0.4.0
PORTREVISION=	3
CATEGORIES=	textproc gnustep
MASTER_SITES=	GNUSTEP/usr-apps
DISTNAME=	EasyDiff-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNUstep graphical diff

LICENSE=	GPLv2 # or later; COPYING has GPLv3

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/Local/Applications/EasyDiff.app/EasyDiff

.include <bsd.port.mk>
