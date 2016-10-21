# $FreeBSD$

PORTNAME=	ptexenc
PORTVERSION=	1.3.3
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	TEX_CTAN/systems/texlive/Source/
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-20150521-source
DIST_SUBDIR=	TeX

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Library for Japanese pTeX and its tools

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		iconv libtool pathfix pkgconfig tar:xz
USE_TEX=	kpathsea
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/ptexenc
EXTRACT_AFTER_ARGS=	${EXTRACT_FILES:S/^/${DISTNAME}\//}
EXTRACT_FILES=	build-aux texk/ptexenc
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-kanji-iconv \
		--with-system-kpathsea \
		--with-kpathsea-includes=${LOCALBASE}/include \
		--with-kpathsea-libdir=${LOCALBASE}/lib
LIBS+=		-L${ICONV_PREFIX}/lib ${ICONV_LIB}
CPPFLAGS+=	-I${ICONV_PREFIX}/include
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
