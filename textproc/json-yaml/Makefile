# $FreeBSD$

PORTNAME=	json-yaml
DISTVERSION=	1.1.2
CATEGORIES=	textproc

MAINTAINER=	ik@sjmulder.nl
COMMENT=	Convert JSON to YAML

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libyajl.so:devel/yajl \
		libyaml.so:textproc/libyaml

MAKE_ARGS+=	MANPREFIX=${PREFIX}/man

USE_GITHUB=	yes
GH_ACCOUNT=	sjmulder

PLIST_FILES=	bin/json-yaml \
		man/man1/json-yaml.1.gz

.include <bsd.port.mk>
