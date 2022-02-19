PORTNAME=	formats
PORTVERSION=	${TEXLIVE_VERSION}
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	#empty
PKGNAMEPREFIX=	tex-
DISTFILES=	#empty
EXTRACT_ONLY=	#empty

MAINTAINER=	tex@FreeBSD.org
COMMENT=	Formats for basic TeX engines and the 'latex' command

USE_TEX=	basic fmtutil texhash texmf web2c

NO_ARCH=	yes
NO_BUILD=	yes
NO_INSTALL=	yes

TEXHASHDIRS=	${TEXMFVARDIR}
TEX_FORMATS=	amstex context csplain eplain latex-bin metafont mex mptopdf \
		pdftex tex

.include <bsd.port.mk>
