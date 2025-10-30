PORTNAME=	lacheck
DISTVERSION=	1.30
CATEGORIES=	textproc
MASTER_SITES=	TEX_CTAN/systems/texlive/${TEXLIVE_YEAR}
DISTNAME=	texlive-${TEXLIVE_VERSION}-source
DIST_SUBDIR=	TeX

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Tool for finding common mistakes in LaTeX documents
WWW=		https://www.ctan.org/tex-archive/support/lacheck/

LICENSE=	GPLv1+

USES=		cpe tar:xz tex
CPE_VENDOR=	tug

GNU_CONFIGURE=	yes

CONFLICTS_INSTALL=	texlive-base

WRKSRC_SUBDIR=	utils/${PORTNAME}

PLIST_FILES=	bin/lacheck \
		share/man/man1/lacheck.1.gz

.include <bsd.port.mk>
