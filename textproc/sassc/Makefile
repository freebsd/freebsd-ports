# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sassc
PORTVERSION=	3.6.1
PORTREVISION=	0
CATEGORIES=	textproc

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Wrapper around libsass

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsass.so:textproc/libsass

USES=		autoreconf compiler:c++11-lib gmake libtool localbase

GH_ACCOUNT=	sass
GNU_CONFIGURE=	yes

MAKEFILE=	GNUmakefile

PLIST_FILES=	bin/sassc

USE_GITHUB=	yes

post-patch:
	@${ECHO_CMD} "${ECHO_CMD} \"${PORTVERSION}\"" > ${WRKSRC}/version.sh

.include <bsd.port.mk>
