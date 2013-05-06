# $FreeBSD$

PORTNAME=	ptexenc
PORTVERSION=	1.3.0
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2012/
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-20120701-source

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Library for Japanese pTeX and its tools

USE_XZ=		yes
USE_TEX=	kpathsea
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/ptexenc
EXTRACT_AFTER_ARGS=	${EXTRACT_FILES}
EXTRACT_FILES=	${DISTNAME}/build-aux \
		${DISTNAME}/texk/ptexenc
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-system-kpathsea \
		--with-kpathsea-includes=${LOCALBASE}/include \
		--with-kpathsea-libdir=${LOCALBASE}/lib
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
