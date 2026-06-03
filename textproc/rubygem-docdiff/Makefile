PORTNAME=	docdiff
PORTVERSION=	0.7.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Compares two text files by word, by character, or by line
WWW=		https://github.com/hisashim/docdiff

LICENSE=	BSD3CLAUSE

USES=		gem shebangfix

NO_ARCH=	yes

PLIST_FILES=	bin/docdiff

SHEBANG_FILES=	*/*.rb \
		doc/example/docdiffwebui.cgi \
		lib/docdiff/*.rb

.include <bsd.port.mk>
