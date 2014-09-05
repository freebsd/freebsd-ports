# $FreeBSD$

PORTNAME=	formats
PORTVERSION=	20140525
CATEGORIES=	print
MASTER_SITES=	#empty
PKGNAMEPREFIX=	tex-
DISTFILES=	#empty
EXTRACT_ONLY=	#empty

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Formats for Basic TeX Engines

NO_BUILD=	yes
NO_INSTALL=	yes

USE_TEX=	web2c kpathsea texmf texhash fmtutil
TEXHASHDIRS=	${TEXMFVARDIR}
TEX_FORMATS=	amstex context cslatex csplain eplain latex-bin \
		metafont mex mptopdf pdftex tex

.include <bsd.port.mk>
