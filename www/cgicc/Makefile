# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cgicc
PORTVERSION=	3.2.14
CATEGORIES=	www devel
MASTER_SITES=	GNU

MAINTAINER=	5u623l20@gmail.com
COMMENT=	C++ class library for writing CGI applications

LICENSE=	LGPL3 # (or later)

OPTIONS_DEFINE=	DOCS

USES=		gmake pathfix
USE_AUTOTOOLS=	libtool
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOHEADER="${TRUE}" \
		AUTOMAKE="${TRUE}"
USE_LDCONFIG=	yes

CXXFLAGS+=	-Wno-unknown-pragmas

PORTDOCS=	*

DOCS_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
DOCS_CONFIGURE_ENV_OFF=	ac_cv_prog_DOXYGEN="${ECHO_CMD}"

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lstdc++||' ${WRKSRC}/cgicc/Makefile.in
	@${REINPLACE_CMD} -e \
		'/^docdir/s|=.*|= @docdir@|' ${WRKSRC}/doc/Makefile.in

.include <bsd.port.mk>
