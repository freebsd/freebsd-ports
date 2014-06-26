# Created by: Melvyn Sopacua <melvyn@magemana.nl>
# $FreeBSD$

PORTNAME=	n98-magerun
PORTVERSION=	1.89.2
CATEGORIES=	sysutils www
MASTER_SITES=	GITHUB

MAINTAINER=	melvyn@magemana.nl
COMMENT=	CLI tool for inspection and control of Magento installations

USE_PHP=	phar bz2 simplexml pdo_mysql json zlib ctype dom posix
USE_MYSQL=	client

USE_GITHUB=	yes
GH_ACCOUNT=	netz98
GH_PROJECT=	n98-magerun
GH_COMMIT=	37b1e5d
NO_BUILD=	yes

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.phar \
		${STAGEDIR}${PREFIX}/sbin/${PORTNAME}

.include <bsd.port.mk>
