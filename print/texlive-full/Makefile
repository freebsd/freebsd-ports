# $FreeBSD$

PORTNAME=	texlive
DISTVERSION=	20120701
CATEGORIES=	print
MASTER_SITES=	#empty
PKGNAMESUFFIX=	-full
DISTFILES=	#empty
EXTRACT_ONLY=	#empty

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	TeX Live, Full Version

USE_TEX=	texlive full texhash
NO_BUILD=	yes
NO_INSTALL=	yes
NO_MTREE=	yes

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=DOCS

DOCS_USE=	TEX=docs

.include <bsd.port.mk>
