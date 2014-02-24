# Created by: Jin-Sih Lin <linpct@gmail.com>
# $FreeBSD$

PORTNAME=	phalcon
PORTVERSION=	1.2.6
CATEGORIES=	www
MASTER_SITES=	https://github.com/phalcon/cphalcon/archive/v${PORTVERSION}/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	linpct@gmail.com
COMMENT=	Phalcon PHP Framework written in C-language

LICENSE=	BSD3CLAUSE

WRKSRC=		${WRKDIR}/c${PORTNAME}-${PORTVERSION}/build/${ARCH:S/amd64/64/:S/i386/32/}bits

CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--enable-phalcon --prefix=${PREFIX} \
		--with-php-config=${LOCALBASE}/bin/php-config
ONLY_FOR_ARCHS=	amd64 i386

USE_PHP=	pdo
USE_PHPEXT=	yes
USE_PHPIZE=	yes
USE_PHP_BUILD=	yes

.include <bsd.port.mk>
