# $FreeBSD$

PORTNAME=	ptexenc
PORTVERSION=	1.3.2
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2014/
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-20140525-source
DIST_SUBDIR=	TeX

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Library for Japanese pTeX and its tools

USES=		tar:xz libtool
USE_TEX=	kpathsea
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/ptexenc
EXTRACT_AFTER_ARGS=	${EXTRACT_FILES}
EXTRACT_FILES=	${DISTNAME}/build-aux \
		${DISTNAME}/texk/ptexenc
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-system-kpathsea \
		--with-kpathsea-includes=${LOCALBASE}/include \
		--with-kpathsea-libdir=${LOCALBASE}/lib

.include <bsd.port.mk>
