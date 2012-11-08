# Created by: Jin-Sih Lin <linpct@gmail.com>
# $FreeBSD$

PORTNAME=	phalcon
PORTVERSION=	0.6.0
CATEGORIES=	www
MASTER_SITES=	https://github.com/${PORTNAME}/c${PORTNAME}/tarball/${GITVERSION}/
DISTNAME=	${PORTNAME}-c${PORTNAME}-${GITVERSION}

MAINTAINER=	linpct@gmail.com
COMMENT=	Phalcon PHP Framework written in C-language

BUILD_DEPENDS=	${LOCALBASE}/include/php/ext/pdo/php_pdo_driver.h:${PORTSDIR}/databases/php5-pdo
RUN_DEPENDS=	${LOCALBASE}/include/php/ext/pdo/php_pdo_driver.h:${PORTSDIR}/databases/php5-pdo

GITVERSION=	906d0f9
FETCH_ARGS=	-pRr
WRKSRC=		${WRKDIR}/${PORTNAME}-c${PORTNAME}-${GITVERSION}/build/

CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--enable-phalcon --prefix=${PREFIX} --with-php-config=${LOCALBASE}/bin/php-config

USE_PHP=	yes
USE_PHPEXT=	yes
USE_PHPIZE=	yes

.include <bsd.port.mk>
