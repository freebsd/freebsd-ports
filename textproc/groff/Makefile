PORTNAME=	groff
DISTVERSION=	1.24.0
CATEGORIES=	textproc
MASTER_SITES=	GNU

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Software typesetting package
WWW=		https://www.gnu.org/software/groff/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gsfonts>=0:print/gsfonts \
		psselect:print/psutils
RUN_DEPENDS=	psselect:print/psutils

USES=		cpe gmake iconv:wchar_t perl5
CPE_VENDOR=	gnu
USE_CXXSTD=	gnu++98

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-urw-fonts-dir=${LOCALBASE}/share/ghostscript/fonts/ \
			--without-gs \
			--without-x

# Canonicalize to A4 if set.
.if defined(A4) || (defined(PAPERSIZE) && ${PAPERSIZE:tu} == "A4")
PAPERSIZE=	A4
.endif
.if defined(PAPERSIZE)
CONFIGURE_ENV+=	PAGE=${PAPERSIZE}
.endif

CONFLICTS=	heirloom-doctools ja-groff

DATADIR=	${PREFIX}/share/${PORTNAME}/${DISTVERSION}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${DISTVERSION}

INFO=		groff
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=		DOCS EXAMPLES UCHARDET
OPTIONS_DEFAULT=	UCHARDET

UCHARDET_DESC=		Automatic encoding detection in preconv(1)

UCHARDET_LIB_DEPENDS=	libuchardet.so:textproc/uchardet
UCHARDET_USES=		pkgconfig
UCHARDET_CONFIGURE_OFF=	--with-uchardet=no

post-install:
	${INSTALL_DATA} ${FILESDIR}/mdoc.local ${STAGEDIR}${PREFIX}/share/groff/site-tmac
	${REINPLACE_CMD} -i "" -e "s/missing/gs/" ${STAGEDIR}${DATADIR}/font/devhtml/DESC

	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${STAGEDIR}${DOCSDIR}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
	${RM} -r ${STAGEDIR}${DOCSDIR}/examples

	${RLN} ${STAGEDIR}${EXAMPLESDIR}/mom/mom-pdf.pdf ${STAGEDIR}${DOCSDIR}/pdf

post-install-DOCS-off:
	${RM} -r ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-off:
	${RM} -r ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
