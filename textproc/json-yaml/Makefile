PORTNAME=	json-yaml
DISTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	ik@sjmulder.nl
COMMENT=	Convert JSON to YAML
WWW=		https://github.com/sjmulder/json-yaml

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libyajl.so:devel/yajl \
		libyaml.so:textproc/libyaml

USE_GITHUB=	yes
GH_ACCOUNT=	sjmulder

MAKE_ARGS+=	MANPREFIX=${PREFIX}/share/man CFLAGS=-I${PREFIX}/include\ -L${PREFIX}/lib

PLIST_FILES=	bin/json-yaml \
		bin/yaml-json \
		share/man/man1/json-yaml.1.gz \
		share/man/man1/yaml-json.1.gz

.include <bsd.port.mk>
