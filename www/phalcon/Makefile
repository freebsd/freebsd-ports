PORTNAME=	phalcon
DISTVERSIONPREFIX=	v
DISTVERSION=	5.9.3
CATEGORIES=	www
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	franco@opnsense.org
COMMENT=	Phalcon PHP Framework written in C-language
WWW=		https://phalcon.io/

LICENSE=	BSD3CLAUSE

USES=		localbase php:ext
USE_GITHUB=	yes
GH_PROJECT=	c${PORTNAME}
USE_PHP=	mbstring pdo:build session:build

CONFIGURE_ARGS=	--enable-phalcon

WRKSRC_SUBDIR=	build/phalcon

.include <bsd.port.pre.mk>

.if ${PHP_VER} >= 85
.  if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=int-conversion
.  endif

post-patch:
	@${REINPLACE_CMD} -e 's|ext/standard/php_smart_string|Zend/zend_smart_string|' \
		${WRKSRC}/phalcon.zep.c
.endif

.include <bsd.port.post.mk>
