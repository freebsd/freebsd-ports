PORTNAME=	libsass
DISTVERSION=	3.6.6
CATEGORIES=	textproc

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	C/C++ implementation of a Sass compiler
WWW=		https://sass-lang.com/libsass

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf compiler:c++11-lib cpe gmake libtool pathfix
CPE_VENDOR=	sass-lang
PATHFIX_MAKEFILEIN=	GNUmakefile.am
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	sass

GNU_CONFIGURE=	yes
MAKEFILE=	GNUmakefile
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--disable-static

post-patch:
	@${ECHO_CMD} "${ECHO_CMD} \"${DISTVERSION}\"" > ${WRKSRC}/version.sh

.include <bsd.port.mk>
