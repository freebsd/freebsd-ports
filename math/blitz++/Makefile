# ex:ts=8
# Ports collection makefile for:	blitz++
# Date created:			Jul 25, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	blitz++
PORTVERSION=	0.8
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	blitz
DISTNAME=	blitz-${PORTVERSION}

MAINTAINER=	olivier.saut@gmail.com
COMMENT=	A C++ class library for scientific computing

.ifndef NOPORTDOCS
BUILD_DEPENDS=	texi2dvi:${PORTSDIR}/print/teTeX-base
INFO=		blitz
.else
MAKE_ARGS=	NOPORTDOCS=yes
.endif

USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-cxx=gcc --disable-doxygen
MAKE_ARGS+=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

DOCSDIR=	${PREFIX}/share/doc/blitz

INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|g++|\$${CXX}|g ; \
		 s|"-ftemplate-depth-30|"\$${CXXFLAGS} -ftemplate-depth-30|g ; \
		 s|-O2||g' ${WRKSRC}/configure

.include <bsd.port.mk>
