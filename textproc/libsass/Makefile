# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libsass
DISTVERSION=	3.5.0
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	C/C++ implementation of a Sass compiler

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf compiler:c++11-lib gmake libtool pathfix
GH_ACCOUNT=	sass
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
PATHFIX_MAKEFILEIN=	GNUmakefile.am
CONFIGURE_ARGS=	--disable-static
MAKEFILE=	GNUmakefile
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

post-patch:
	@${ECHO_CMD} "${ECHO_CMD} \"${PORTVERSION}\"" > ${WRKSRC}/version.sh

.include <bsd.port.mk>
