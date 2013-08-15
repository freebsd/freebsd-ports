# Created by: Jin-Sih Lin <linpct@gmail.com>
# $FreeBSD$

PORTNAME=	phalcon
PORTVERSION=	1.2.3
CATEGORIES=	www
MASTER_SITES=	https://github.com/phalcon/cphalcon/archive/v${PORTVERSION}/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	linpct@gmail.com
COMMENT=	Phalcon PHP Framework written in C-language

LICENSE=	BSD

FETCH_ARGS=	-pRr
WRKSRC=		${WRKDIR}/c${PORTNAME}-${PORTVERSION}/build/

CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--enable-phalcon --prefix=${PREFIX} \
		--with-php-config=${LOCALBASE}/bin/php-config

USE_PHP=	pdo
USE_PHPEXT=	yes
USE_PHPIZE=	yes
USE_PHP_BUILD=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
WRKSRC:=	${WRKSRC}/64bits
.elif ${ARCH} == "i386"
WRKSRC:=	${WRKSRC}/32bits
.else
BROKEN=		Only support on amd64 or i386
.endif

.include <bsd.port.post.mk>
