PORTNAME=	groff
DISTVERSION=	1.23.0
PORTREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Software typesetting package
WWW=		https://www.gnu.org/software/groff/

LICENSE=	GPLv3

BUILD_DEPENDS=	gsfonts>=0:print/gsfonts \
		psselect:print/psutils
RUN_DEPENDS=	psselect:print/psutils

USES=		cpe gmake iconv:wchar_t makeinfo perl5
CPE_VENDOR=	gnu
USE_CXXSTD=	gnu++98

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-awk=/usr/bin/awk \
			--with-urw-fonts-dir=${LOCALBASE}/share/ghostscript/fonts/ \
			--without-gs \
			--without-x \
			pnmcrop=missing \
			pnmcut=missing \
			pnmtopng=missing \
			pnmtops=missing \
			psselect=missing

# Canonicalize to A4 if set.
.if defined(A4) || (defined(PAPERSIZE) && ${PAPERSIZE:tu} == "A4")
PAPERSIZE=	A4
.endif
.if defined(PAPERSIZE)
CONFIGURE_ENV+=	PAGE=${PAPERSIZE}
.endif

MAKE_JOBS_UNSAFE=	yes

CONFLICTS=	heirloom-doctools ja-groff

DATADIR=	${PREFIX}/share/${PORTNAME}/${DISTVERSION}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${DISTVERSION}
EXAMPLESDIR=	${DOCSDIR}/examples

INFO=		groff

OPTIONS_DEFINE=		UCHARDET
OPTIONS_DEFAULT=	UCHARDET

UCHARDET_DESC=		Automatic encoding detection in preconv(1)
UCHARDET_LIB_DEPENDS=	libuchardet.so:textproc/uchardet
UCHARDET_USES=		pkgconfig
UCHARDET_CONFIGURE_OFF=	--with-uchardet=no

post-install:
	${INSTALL_DATA} ${FILESDIR}/mdoc.local ${STAGEDIR}${PREFIX}/share/groff/site-tmac
	${REINPLACE_CMD} -i "" -e "s/missing/gs/" ${STAGEDIR}${DATADIR}/font/devhtml/DESC

.include <bsd.port.mk>
