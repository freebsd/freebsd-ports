PORTNAME=	libreswan
DISTVERSION=	4.6
CATEGORIES=	security
MASTER_SITES=	https://download.libreswan.org/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	IPsec and IKE based firewall

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gawk:lang/gawk \
		xmlto:textproc/xmlto # build requires xmlto, but manpages aren't installed: https://github.com/libreswan/libreswan/issues/479
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libevent.so:devel/libevent \
		libldns.so:dns/ldns \
		libnspr4.so:devel/nspr \
		libnss3.so:security/nss \
		libunbound.so:dns/unbound

USES=		bison cpe gmake pkgconfig python

CFLAGS+=	-I${WRKSRC}/include/unbound

MAKE_ARGS=	PKG_BASE=${LOCALBASE} \
		NSS_CFLAGS="`pkg-config --cflags nss`" NSS_LDFLAGS="`pkg-config --libs nss`" \
		NSPR_LDFLAGS="`pkg-config --libs nspr`" \
		CRYPT_LDFLAGS=-lcrypt \
		USE_PTHREAD_SETSCHEDPRIO=false \
		WERROR_CFLAGS=""  \
		PYTHON_BINARY=${PYTHON_CMD}

BINARY_ALIAS=	awk=gawk

OPTIONS_DEFINE=	DOCS

post-configure:
	@cd ${WRKSRC}/mk/defaults && \
		${RLN} netbsd.mk freebsd.mk

post-install:
.for f in _import_crl addconn algparse cavp dncheck ecdsasigkey enumcheck hunkcheck ipcheck jambufcheck keyidcheck pluto readwriteconf rsasigkey showhostkey timecheck whack
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/ipsec/${f}
.endfor

.include <bsd.port.mk>
