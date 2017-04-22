# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	docdiff
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Compares two text files by word, by character, or by line

LICENSE=	BSD3CLAUSE

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem shebangfix
SHEBANG_FILES=	test/*.rb devutil/*.rb \
		docdiffwebui.cgi

PLIST_FILES=	bin/docdiff

.include <bsd.port.mk>
