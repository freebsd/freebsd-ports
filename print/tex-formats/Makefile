PORTNAME=	formats
PORTVERSION=	20150521
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	#empty
PKGNAMEPREFIX=	tex-
DISTFILES=	#empty
EXTRACT_ONLY=	#empty

MAINTAINER=	freebsd-tex@FreeBSD.org
COMMENT=	Formats for basic TeX engines and the 'latex' command

NO_ARCH=	yes
NO_BUILD=	yes
NO_INSTALL=	yes

USE_TEX=	web2c basic texmf fmtutil texhash
TEXHASHDIRS=	${TEXMFVARDIR}
TEX_FORMATS=	amstex context cslatex csplain eplain latex-bin \
		metafont mex mptopdf pdftex tex

.include <bsd.port.mk>
