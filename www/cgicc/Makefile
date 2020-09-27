# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cgicc
PORTVERSION=	3.2.19
PORTREVISION=	1
CATEGORIES=	www devel
MASTER_SITES=	GNU

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	C++ class library for writing CGI applications

LICENSE=	LGPL3+

USES=		autoreconf:build compiler:gcc-c++11-lib libtool pathfix
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
PORTDOCS=	*

OPTIONS_DEFINE=	DOXYGEN DOCS
DOXYGEN_IMPLIES=	DOCS
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_CONFIGURE_ENV_OFF=	ac_cv_prog_DOXYGEN="${ECHO_CMD}"

post-patch:
	@${REINPLACE_CMD} -e \
		'/^docdir/s|=.*|= @docdir@|' ${WRKSRC}/doc/Makefile.in

.include <bsd.port.mk>
