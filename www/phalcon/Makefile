# Created by: Jin-Sih Lin <linpct@gmail.com>
# $FreeBSD$

PORTNAME=	phalcon
PORTVERSION=	2.0.0
CATEGORIES=	www

MAINTAINER=	linpct@gmail.com
COMMENT=	Phalcon PHP Framework written in C-language

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	phalcon
GH_PROJECT=	c${PORTNAME}
GH_TAGNAME=	${PORTNAME}-v${PORTVERSION}

PBITS=		${ARCH:S/amd64/64/:S/i386/32/:S/x86_64/64/}
WRKSRC=		${WRKDIR}/c${PORTNAME}-${GH_TAGNAME}/build/${PBITS}bits

CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--enable-phalcon --prefix=${PREFIX} \
		--with-php-config=${LOCALBASE}/bin/php-config
ONLY_FOR_ARCHS=	amd64 i386

USE_PHP=	hash pdo
USE_PHPEXT=	yes
USE_PHPIZE=	yes
USE_PHP_BUILD=	yes

.include <bsd.port.mk>
