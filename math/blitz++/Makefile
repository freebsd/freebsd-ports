# ex:ts=8
# Ports collection makefile for:	blitz++
# Date created:			Jul 25, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	blitz++
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	blitz
DISTNAME=	Blitz++-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C++ class library for scientific computing

USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-cxx=gcc --enable-optimize --disable-debug
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

INFO=		blitz
DOCSDIR=	${PREFIX}/share/doc/blitz

post-patch:
	@${FIND} ${WRKSRC}/manual -name "Makefile.in" | ${XARGS} \
		${REINPLACE_CMD} -e 's|[(]prefix[)]|(datadir)|g'
	@${REINPLACE_CMD} -e 's|g++|\$${CXX}|g ; \
		 s|"-ftemplate-depth-30|"\$${CXXFLAGS} -ftemplate-depth-30|g ; \
		 s|-O2||g' ${WRKSRC}/configure

.include <bsd.port.mk>
