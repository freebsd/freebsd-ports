PORTNAME=	yaml
DISTVERSION=	2.2.4
CATEGORIES=	textproc pear

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	YAML-1.1 parser and emitter
WWW=		https://pecl.php.net/package/yaml

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libyaml.so:textproc/libyaml

USES=		php:pecl

.include <bsd.port.pre.mk>
post-patch:
.if ${PHP_VER} >= 85
	@${REINPLACE_CMD} -e 's|ext/standard/php_smart_string.h|Zend/zend_smart_string.h|' \
		${WRKSRC}/php_yaml.h
.endif
.include <bsd.port.post.mk>
