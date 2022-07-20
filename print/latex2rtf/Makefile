PORTNAME=	latex2rtf
DISTVERSION=	2.3.17
CATEGORIES=	print
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-unix/${PORTVERSION} \
		TEX_CTAN

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Translator from LaTeX to RTF

USES=		cpe shebangfix makeinfo
SHEBANG_FILES=	${WRKSRC}/scripts/latex2png

CPE_VENDOR=	latex2rtf_project

OPTIONS_DEFINE=	LATEX2PNG
LATEX2PNG_DESC=	Install latex2png utility
OPTIONS_SUB=	yes

LATEX2PNG_USES=		magick:6,run
LATEX2PNG_USE=		TEX=dvipsk,latex,xetex

MAKE_ARGS+=	MANDIR=${PREFIX}/man/man1 CFGDIR=${DATADIR}/cfg \
		BINDIR=${PREFIX}/bin

.include <bsd.port.mk>
