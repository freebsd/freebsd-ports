# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	docdiff
PORTVERSION=	0.5.0
PORTREVISION=	2
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Compares two text files by word, by character, or by line

LICENSE=	BSD3CLAUSE

USES=		gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/docdiff

SHEBANG_FILES=	docdiffwebui.cgi langfilter.rb */*.rb lib/docdiff/*.rb

.include <bsd.port.mk>
