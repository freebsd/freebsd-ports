# Created by: ijliao
# $FreeBSD$

PORTNAME=	blitz++
PORTVERSION=	0.9
PORTREVISION=	8
CATEGORIES=	math
MASTER_SITES=	SF/blitz/blitz/Blitz%2B%2B%20${PORTVERSION}
DISTNAME=	blitz-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ class library for scientific computing

OPTIONS_DEFINE=	DOCS

DOCS_USE=	TEX=dvipsk,formats
DOCS_USES=	makeinfo
DOCS_INFO=	blitz
DOCS_BUILD_DEPENDS=	texi2dvi:print/texinfo \
			texi2html:textproc/texi2html
DOCS_MAKE_ARGS_OFF=	NOPORTDOCS=yes

GNU_CONFIGURE=	yes
USES=	libtool pathfix gmake
CONFIGURE_ARGS=	--with-cxx=gcc --disable-doxygen --enable-shared
MAKE_ARGS+=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"
MAKE_JOBS_UNSAFE=	yes
INSTALL_TARGET=	install-strip

DOCSDIR=	${PREFIX}/share/doc/blitz

USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|g++|\$${CXX}|g ; \
		 s|"-ftemplate-depth-30|"\$${CXXFLAGS} -ftemplate-depth-30|g ; \
		 s|-O2||g' ${WRKSRC}/configure

.include <bsd.port.mk>
