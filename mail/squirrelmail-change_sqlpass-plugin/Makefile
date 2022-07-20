PORTNAME=	change-sqlpass
PORTVERSION=	3.3
PORTREVISION=	3
CATEGORIES=	mail www
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}-1.2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Allows users to change their passwords stored in a SQL database

IGNORE_WITH_PHP=	82
USE_SM_COMPAT=	yes

RUN_DEPENDS=	${LOCALBASE}/share/pear/DB.php:databases/pear-DB@${PHP_FLAVOR}

SQUIRREL_PLUGIN_NAME=	${PORTNAME:S/-/_/}

.include "${.CURDIR}/../squirrelmail/bsd.squirrelmail.mk"
.include <bsd.port.mk>
