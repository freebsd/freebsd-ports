# $FreeBSD$

PORTNAME=	openggsn
PORTVERSION=	0.92
CATEGORIES=	net
MASTER_SITES=	http://git.osmocom.org/${PORTNAME}/snapshot/ \
		http://chaosophia.net/downloads/osmocom/${PORTNAME}/

MAINTAINER=	koue@chaosophia.net
COMMENT=	Implementation of the Gateway GPRS Support Node element

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=    libosmocore.so:devel/libosmocore

GNU_CONFIGURE=	yes
USES=		autoreconf gmake libtool pathfix pkgconfig

USE_LDCONFIG=	yes

post-patch:
	${ECHO_CMD} ${PORTVERSION} > ${WRKSRC}/.tarball-version

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgtp.so.0

.include <bsd.port.mk>
