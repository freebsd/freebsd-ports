# $FreeBSD$

PORTNAME=	timeout_user
PORTVERSION=	1.1.1
PORTREVISION=	5
CATEGORIES=	mail www
DISTNAME=	${PORTNAME}-${PORTVERSION}-0.5

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automatically logs a user out if they're idle for a set amount of time

LICENSE=	GPLv2

USE_SM_COMPAT=	yes
USE_GENERIC_PKGMESSAGE=	yes


post-patch:
	@${MV} ${WRKSRC}/${SQUIRREL_PLUGIN_NAME}/config.php ${WRKSRC}/${SQUIRREL_PLUGIN_NAME}/config.php.sample

.include "${.CURDIR}/../squirrelmail/bsd.squirrelmail.mk"
.include <bsd.port.mk>
