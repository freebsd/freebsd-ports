PORTNAME=	n98-magerun
PORTVERSION=	1.98.0
CATEGORIES=	sysutils www
MASTER_SITES=	https://files.magerun.net/ \
		https://www.freebsd.systems/files/
EXTRACT_SUFX=	.phar

MAINTAINER=	lukasz@wasikowski.net
COMMENT=	CLI tool for inspection and control of Magento installations

LICENSE=	MIT

USES=		mysql:client php:cli
USE_PHP=	phar bz2 simplexml pdo_mysql json zlib ctype dom posix

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	sbin/n98-magerun

do-extract:
	@${MKDIR} ${WRKSRC}/
	${CP} ${_DISTDIR}/${PORTNAME}-${PORTVERSION}.phar ${WRKSRC}/

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}-${PORTVERSION}.phar \
		${STAGEDIR}${PREFIX}/sbin/${PORTNAME}

.include <bsd.port.mk>
