PORTNAME=	go-md2man
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0
PORTREVISION=	3
CATEGORIES=	textproc

MAINTAINER=	mateusz@serveraptor.com
COMMENT=	Converts Markdown into roff (man pages)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		go:modules
USE_GITHUB=	yes

GH_ACCOUNT=	cpuguy83
GH_SUBDIR=	go-md2man

GH_TUPLE=	russross:blackfriday:v2.0.1:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		shurcooL:sanitized_anchor_name:v1.0.0:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
