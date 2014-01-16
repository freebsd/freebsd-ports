# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cgicc
PORTVERSION=	3.2.12
CATEGORIES=	www devel
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
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

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
.else
CONFIGURE_ENV+=	ac_cv_prog_DOXYGEN="${ECHO_CMD}"
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lstdc++||' ${WRKSRC}/cgicc/Makefile.in
	@${REINPLACE_CMD} -e \
		'/^docdir/s|=.*|= @docdir@|' ${WRKSRC}/doc/Makefile.in

.include <bsd.port.mk>
