# Created by: ijliao
# $FreeBSD$

PORTNAME=	blitz++
PORTVERSION=	0.9
PORTREVISION=	7
CATEGORIES=	math
MASTER_SITES=	SF/blitz/blitz/Blitz%2B%2B%20${PORTVERSION}
DISTNAME=	blitz-${PORTVERSION}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	A C++ class library for scientific computing

.ifndef NOPORTDOCS
BUILD_DEPENDS=	dvips:${PORTSDIR}/print/dvipsk-tetex \
		texi2dvi:${PORTSDIR}/print/texinfo
INFO=		blitz
.else
MAKE_ARGS=	NOPORTDOCS=yes
.endif

USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USES=	pathfix
CONFIGURE_ARGS=	--with-cxx=gcc --disable-doxygen
MAKE_ARGS+=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"
MAKE_JOBS_UNSAFE=	yes

DOCSDIR=	${PREFIX}/share/doc/blitz

USE_LDCONFIG=	yes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|g++|\$${CXX}|g ; \
		 s|"-ftemplate-depth-30|"\$${CXXFLAGS} -ftemplate-depth-30|g ; \
		 s|-O2||g' ${WRKSRC}/configure

.include <bsd.port.mk>
