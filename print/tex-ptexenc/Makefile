PORTNAME=	ptexenc
DISTVERSION=	1.4.6
CATEGORIES=	print
MASTER_SITES=	TEX_CTAN/systems/texlive/Source/${TEXLIVE_YEAR}
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-${TEXLIVE_VERSION}-source
DIST_SUBDIR=	TeX

MAINTAINER=	tex@FreeBSD.org
COMMENT=	Library for Japanese pTeX and its tools

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		iconv libtool pathfix pkgconfig tar:xz tex
USE_LDCONFIG=	yes
USE_TEX=	kpathsea

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-kanji-iconv \
		--with-system-kpathsea \
		--with-kpathsea-includes=${LOCALBASE}/include \
		--with-kpathsea-libdir=${LOCALBASE}/lib

INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${ICONV_PREFIX}/include
LIBS+=		-L${ICONV_PREFIX}/lib ${ICONV_LIB}

EXTRACT_AFTER_ARGS=	${EXTRACT_FILES:S/^/${DISTNAME}\//}

WRKSRC=		${WRKDIR}/${DISTNAME}/texk/ptexenc

PLIST_SUB=	VERSION=${PORTVERSION}

EXTRACT_FILES=	build-aux texk/ptexenc

.include <bsd.port.mk>
