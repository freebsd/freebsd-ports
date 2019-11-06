# $FreeBSD$

PORTNAME=	xpdfopen
PORTVERSION=	0.86
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2015/
DISTNAME=	texlive-${DISTVERSION_TEXLIVE_SOURCE}-source
DIST_SUBDIR=	TeX

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Command line utility for PDF viewers

CONFLICTS=	texlive-base-20150521_[1-4]

USES=		tar:xz xorg
USE_XORG=	x11 xmu
EXTRACT_AFTER_ARGS=	${EXTRACT_FILES:S,^,${DISTNAME}/,}
EXTRACT_FILES=	build-aux \
		utils/xpdfopen
DISTVERSION_TEXLIVE_SOURCE=	20150521
WRKSRC=		${WRKDIR}/${DISTNAME}/utils/xpdfopen
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/pdfclose \
		bin/pdfopen \
		man/man1/pdfclose.1.gz \
		man/man1/pdfopen.1.gz

.include <bsd.port.mk>
