PORTNAME=	xpdfopen
DISTVERSION=	${TEXLIVE_VERSION}
CATEGORIES=	print
MASTER_SITES=	TEX_CTAN/systems/texlive/${TEXLIVE_YEAR}/
DISTNAME=	texlive-${TEXLIVE_VERSION}-source
DIST_SUBDIR=	TeX

MAINTAINER=	tex@FreeBSD.org
COMMENT=	Command line utility for PDF viewers

USES=		localbase:ldflags tar:xz tex xorg
USE_XORG=	x11 xmu

EXTRACT_FILES=	build-aux utils/xpdfopen
GNU_CONFIGURE=	yes

EXTRACT_AFTER_ARGS=	${EXTRACT_FILES:S,^,${DISTNAME}/,}

WRKSRC=		${WRKDIR}/${DISTNAME}/utils/xpdfopen

PLIST_FILES=	bin/pdfclose \
		bin/pdfopen \
		share/man/man1/pdfclose.1.gz \
		share/man/man1/pdfopen.1.gz

.include <bsd.port.mk>
