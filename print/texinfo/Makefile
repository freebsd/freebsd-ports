PORTNAME=	texinfo
PORTVERSION=	7.1
PORTREVISION=	12
PORTEPOCH=	1
CATEGORIES=	print
MASTER_SITES=	GNU \
		LOCAL/sunpoet/texinfo:DEFAULT,local
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		htmlxref.cnf-${HTMLXREF_CNF_RELDATE}:local \
		texi2dvi-${TEXI2DVI_RELDATE}:local \
		texi2pdf-${TEXI2PDF_RELDATE}:local \
		texinfo.tex-${TEXINFO_TEX_RELDATE}:local
DIST_SUBDIR=	texinfo
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Typeset documentation system with multiple format output
WWW=		https://www.gnu.org/software/texinfo/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	help2man:misc/help2man \
		${RUN_DEPENDS}
RUN_DEPENDS=	p5-Locale-libintl>=0:devel/p5-Locale-libintl \
		p5-Text-Unidecode>=0:converters/p5-Text-Unidecode \
		p5-Unicode-EastAsianWidth>=0:textproc/p5-Unicode-EastAsianWidth

USES=		charsetfix cpe gmake iconv:wchar_t libtool ncurses perl5 tar:xz tex

CONFIGURE_ARGS=	--with-external-libintl-perl \
		--with-external-Text-Unidecode \
		--with-external-Unicode-EastAsianWidth
CONFIGURE_ENV=	PERL_EXT_CC="${CC}"
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip install-tex
MAKE_ARGS=	PERL=${PERL} TEXMF=${LOCALBASE}/${TEXMFDIR}
PKGDEINSTALL=	${PKGINSTALL}

INFO=		info-stnd texi2any_api texi2any_internals texinfo

CPE_VENDOR=	gnu

# Use the date on https://ftp.gnu.org/gnu/texinfo/
HTMLXREF_CNF_RELDATE=	20250626
TEXI2DVI_RELDATE=	20241223
TEXI2PDF_RELDATE=	20241223
TEXINFO_TEX_RELDATE=	20250711

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

post-patch:
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/texinfo.tex-${TEXINFO_TEX_RELDATE} ${WRKSRC}/doc/texinfo.tex
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/htmlxref.cnf-${HTMLXREF_CNF_RELDATE} ${WRKSRC}/util/htmlxref.cnf
	@${INSTALL_SCRIPT} ${DISTDIR}/${DIST_SUBDIR}/texi2dvi-${TEXI2DVI_RELDATE} ${WRKSRC}/util/texi2dvi
	@${INSTALL_SCRIPT} ${DISTDIR}/${DIST_SUBDIR}/texi2pdf-${TEXI2PDF_RELDATE} ${WRKSRC}/util/texi2pdf

post-install:
	${INSTALL_DATA} ${WRKSRC}/util/htmlxref.cnf ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
