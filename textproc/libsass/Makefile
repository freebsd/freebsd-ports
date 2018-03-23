# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libsass
DISTVERSION=	3.5.0
CATEGORIES=	textproc

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	C/C++ implementation of a Sass compiler

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

INSTALL_TARGET=	install-strip

GH_ACCOUNT=	sass
GNU_CONFIGURE=	yes

MAKEFILE=	GNUmakefile

PATHFIX_MAKEFILEIN=	GNUmakefile.am

STATIC_PIC=	${PORTNAME}_pic.a

USES=		autoreconf compiler:c++11-lib gmake libtool pathfix
USE_GITHUB=	yes
USE_LDCONFIG=	yes

post-build:
	@(cd ${WRKSRC}/src/.libs && ${AR} rf ${STATIC_PIC} *.o)

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/.libs/${STATIC_PIC} ${STAGEDIR}${PREFIX}/lib

post-patch:
	@${ECHO_CMD} "${ECHO_CMD} \"${PORTVERSION}\"" > ${WRKSRC}/version.sh

.include <bsd.port.mk>
