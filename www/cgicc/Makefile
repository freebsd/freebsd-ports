PORTNAME=	cgicc
PORTVERSION=	3.2.20
CATEGORIES=	www devel
MASTER_SITES=	GNU

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	C++ class library for writing CGI applications
WWW=		https://www.gnu.org/software/cgicc/

LICENSE=	LGPL3+

USES=		autoreconf:build libtool pathfix
USE_CXXSTD=	c++11
USE_GCC=	12
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen
DOCS_CONFIGURE_ENV_OFF=	ac_cv_prog_DOXYGEN="${ECHO_CMD}"

post-patch:
	@${REINPLACE_CMD} -e \
		'/^docdir/s|=.*|= @docdir@|' ${WRKSRC}/doc/Makefile.in

.include <bsd.port.mk>
