# Created by: Jin-Sih Lin <linpct@gmail.com>
# $FreeBSD$

PORTNAME=	phalcon
PORTVERSION=	0.8.0
CATEGORIES=	www
MASTER_SITES=	https://github.com/${PORTNAME}/c${PORTNAME}/tarball/${GITVERSION}/
DISTNAME=	${PORTNAME}-c${PORTNAME}-${GITVERSION}

MAINTAINER=	linpct@gmail.com
COMMENT=	Phalcon PHP Framework written in C-language

BUILD_DEPENDS=	${LOCALBASE}/include/php/ext/pdo/php_pdo_driver.h:${PORTSDIR}/databases/php5-pdo
RUN_DEPENDS=	${LOCALBASE}/include/php/ext/pdo/php_pdo_driver.h:${PORTSDIR}/databases/php5-pdo

GITVERSION=	10cbc51
FETCH_ARGS=	-pRr
WRKSRC=		${WRKDIR}/${PORTNAME}-c${PORTNAME}-${GITVERSION}/build/

CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--enable-phalcon --prefix=${PREFIX} --with-php-config=${LOCALBASE}/bin/php-config

USE_PHP=	yes
USE_PHPEXT=	yes
USE_PHPIZE=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
WRKSRC:=	${WRKSRC}/64bits
.elif ${ARCH} == "i386"
WRKSRC:=	${WRKSRC}/32bits
.else
BROKEN=		Only support on amd64 or i386
.endif

.include <bsd.port.post.mk>
