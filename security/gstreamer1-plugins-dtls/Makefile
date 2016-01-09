# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	security

COMMENT=	GStreamer Datagram TLS (dtls) plugin

GST_PLUGIN=	dtls
DIST=		bad

# we don't have a way to specify this in ${MASTERDIR}/Makefile.common
USE_OPENSSL=	yes
CONFIGURE_ENV=	DTLS_CFLAGS="-I${OPENSSLINC}" \
		DTLS_LIBS="-L${OPENSSLLIB} -lcrypto -lssl"

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

.include "${MASTERDIR}/Makefile"
