# $FreeBSD$

PORTNAME=	formats
PORTVERSION=	20120701
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	#empty
PKGNAMEPREFIX=	tex-
DISTFILES=	#empty
EXTRACT_ONLY=	#empty

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Formats for Basic TeX Engines

NO_BUILD=	yes
USE_TEX=	texlive web2c kpathsea texmf texhash fmtutil
TEXHASHDIRS=	${TEXMFVARDIR}
TEX_FORMATS=	amstex context cslatex eplain latex-bin \
		metafont mex mltex mptopdf pdftex tex texsis

NO_STAGE=	yes
do-install:
	@${DO_NADA}

.include <bsd.port.mk>
