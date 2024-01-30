PORTNAME=	latex2rtf
DISTVERSION=	2.3.18
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-unix/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}a

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Translator from LaTeX to RTF
WWW=		https://latex2rtf.sourceforge.net/

LICENSE=	GPLv2+

USES=		cpe shebangfix
CPE_VENDOR=	latex2rtf_project

SHEBANG_FILES=	${WRKSRC}/scripts/latex2png

MAKE_ARGS+=	MANDIR=${PREFIX}/share/man/man1 CFGDIR=${DATADIR}/cfg \
		BINDIR=${PREFIX}/bin

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	LATEX2PNG
OPTIONS_SUB=	yes

LATEX2PNG_DESC=	Install latex2png utility

LATEX2PNG_USES=		magick:6,run tex
LATEX2PNG_USE=		TEX=dvipsk,latex,xetex

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
