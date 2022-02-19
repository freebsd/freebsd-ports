PORTNAME=	texlive
DISTVERSION=	${TEXLIVE_VERSION}
CATEGORIES=	print
PKGNAMESUFFIX=	-full

MAINTAINER=	tex@FreeBSD.org
COMMENT=	TeX Live, Full Version

USE_TEX=	full texhash
USES=		metaport

OPTIONS_DEFINE=	DOCS SOURCE

DOCS_USE=	TEX=docs
SOURCE_DESC=	Install source files
SOURCE_USE=	TEX=source

.include <bsd.port.mk>
