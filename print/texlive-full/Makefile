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

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
USE_TEX+=	docs
.endif

do-install:
	@${DO_NADA}

.include <bsd.port.mk>
