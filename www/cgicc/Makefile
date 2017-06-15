# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cgicc
PORTVERSION=	3.2.16
PORTREVISION=	1
CATEGORIES=	www devel
MASTER_SITES=	GNU

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	C++ class library for writing CGI applications

LICENSE=	LGPL3+

OPTIONS_DEFINE=	DOXYGEN

USES=		gmake pathfix libtool
GNU_CONFIGURE=	yes
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOHEADER="${TRUE}" \
		AUTOMAKE="${TRUE}"
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CXXFLAGS+=	-Wno-unknown-pragmas

PORTDOCS=	*

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_CONFIGURE_ENV_OFF=	ac_cv_prog_DOXYGEN="${ECHO_CMD}"

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lstdc++||' ${WRKSRC}/cgicc/Makefile.in
	@${REINPLACE_CMD} -e \
		'/^docdir/s|=.*|= @docdir@|' ${WRKSRC}/doc/Makefile.in

.include <bsd.port.mk>
