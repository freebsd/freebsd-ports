PORTNAME=	libsass
DISTVERSION=	3.6.4
PORTREVISION=	0
CATEGORIES=	textproc

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	C/C++ implementation of a Sass compiler

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf compiler:c++11-lib cpe gmake libtool pathfix
CPE_VENDOR=	sass-lang
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--disable-static

GH_ACCOUNT=	sass
GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

MAKEFILE=	GNUmakefile

PATHFIX_MAKEFILEIN=	GNUmakefile.am

post-patch:
	@${ECHO_CMD} "${ECHO_CMD} \"${PORTVERSION}\"" > ${WRKSRC}/version.sh

.include <bsd.port.mk>
