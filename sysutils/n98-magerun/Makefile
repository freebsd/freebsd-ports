# Created by: Melvyn Sopacua <melvyn@magemana.nl>
# $FreeBSD$

PORTNAME=	n98-magerun
PORTVERSION=	1.97.12
CATEGORIES=	sysutils www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CLI tool for inspection and control of Magento installations

LICENSE=	MIT

USE_PHP=	phar bz2 simplexml pdo_mysql json zlib ctype dom posix
USE_MYSQL=	client

USE_GITHUB=	yes
GH_ACCOUNT=	netz98
NO_BUILD=	yes

PLIST_FILES=	sbin/n98-magerun

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.phar \
		${STAGEDIR}${PREFIX}/sbin/${PORTNAME}

.include <bsd.port.mk>
