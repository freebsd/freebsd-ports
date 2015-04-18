# $FreeBSD$

PORTNAME=	openggsn
PORTVERSION=	0.91
CATEGORIES=	net
MASTER_SITES=	http://chaosophia.net/downloads/osmocom/${PORTNAME}/ \
		http://ns1.chaosophia.net/downloads/osmocom/${PORTNAME}/

MAINTAINER=	koue@chaosophia.net
COMMENT=	Implementation of the Gateway GPRS Support Node element

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		autoreconf gmake libtool

post-patch:
	${REINPLACE_CMD} -e 's|pkgconfigdir.*|pkgconfigdir = ${PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.am
	${ECHO_CMD} ${PORTVERSION} > ${WRKSRC}/.tarball-version

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgtp.so.0

.include <bsd.port.mk>
