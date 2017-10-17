# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sassc
PORTVERSION=	3.4.2
PORTREVISION=	2
CATEGORIES=	textproc

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Wrapper around libsass

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsass.so:textproc/libsass

USE_GITHUB=	yes
GH_ACCOUNT=	sass

USES=		autoreconf compiler:c++11-lib gmake libtool localbase
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/sassc

post-patch:
	@${ECHO_CMD} "${ECHO_CMD} \"${PORTVERSION}\"" > ${WRKSRC}/version.sh

.include <bsd.port.mk>
