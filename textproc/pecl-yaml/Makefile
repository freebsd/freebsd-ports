# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yaml
PORTVERSION=	2.1.0
CATEGORIES=	textproc pear

PATCH_SITES=	https://github.com/php/pecl-file_formats-yaml/commit/
PATCHFILES=	ebc51a7314881805f9b8fda2ac19285465f48d3e.patch:-p1

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	YAML-1.1 parser and emitter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libyaml.so:textproc/libyaml

USES=		php:pecl

.include <bsd.port.mk>
