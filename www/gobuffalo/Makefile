PORTNAME=	gobuffalo
PORTVERSION=	0.16.27
DISTVERSIONPREFIX=	v
PORTREVISION=	29
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Go web development eco-system, designed to make the life easier
WWW=		https://gobuffalo.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	git:devel/git

USES=		go:modules,run

GO_MODULE=	github.com/gobuffalo/buffalo
GO_TARGET=	./buffalo
GO_BUILDFLAGS=	-tags "${TAGS}"

PLIST_FILES=	bin/buffalo

OPTIONS_DEFINE=	SQLITE
OPTIONS_DEFAULT=	SQLITE YARN
OPTIONS_RADIO=	NODE
OPTIONS_RADIO_NODE=	NPM YARN

NPM_DESC=	Use npm package manager
YARN_DESC=	Use yarn package manager

SQLITE_VARS=	tags+=sqlite

NPM_RUN_DEPENDS=	npm>=0:www/npm
YARN_RUN_DEPENDS=	yarn>=0:www/yarn

.include <bsd.port.mk>
