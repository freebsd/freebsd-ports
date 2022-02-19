PORTNAME=	xpdfopen
PORTVERSION=	0.86
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	TEX_CTAN/systems/texlive/${TEXLIVE_YEAR}/
DISTNAME=	texlive-${TEXLIVE_VERSION}-source
DIST_SUBDIR=	TeX

MAINTAINER=	tex@FreeBSD.org
COMMENT=	Command line utility for PDF viewers

USES=		localbase:ldflags tar:xz xorg
USE_TEX=	yes
USE_XORG=	x11 xmu

EXTRACT_FILES=	build-aux utils/xpdfopen
GNU_CONFIGURE=	yes

CONFLICTS=	texlive-base-*

EXTRACT_AFTER_ARGS=	${EXTRACT_FILES:S,^,${DISTNAME}/,}

WRKSRC=		${WRKDIR}/${DISTNAME}/utils/xpdfopen

PLIST_FILES=	bin/pdfclose \
		bin/pdfopen \
		man/man1/pdfclose.1.gz \
		man/man1/pdfopen.1.gz

.include <bsd.port.mk>
