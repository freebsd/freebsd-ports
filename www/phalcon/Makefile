# Created by: Jin-Sih Lin <linpct@gmail.com>
# $FreeBSD$

PORTNAME=	phalcon
PORTVERSION=	1.3.0
CATEGORIES=	www
MASTER_SITES=	https://github.com/phalcon/cphalcon/archive/${PORTVERSION}/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	linpct@gmail.com
COMMENT=	Phalcon PHP Framework written in C-language

LICENSE=	BSD3CLAUSE

PBITS=		${ARCH:S/amd64/64/:S/i386/32/:S/x86_64/64/}
WRKSRC=		${WRKDIR}/c${PORTNAME}-${PORTVERSION}/build/${PBITS}bits

CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--enable-phalcon --prefix=${PREFIX} \
		--with-php-config=${LOCALBASE}/bin/php-config
ONLY_FOR_ARCHS=	amd64 i386

USE_PHP=	hash pdo
USE_PHPEXT=	yes
USE_PHPIZE=	yes
USE_PHP_BUILD=	yes

.include <bsd.port.mk>
