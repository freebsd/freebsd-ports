PORTNAME=	libreswan
DISTVERSION=	4.4
CATEGORIES=	security
MASTER_SITES=	https://download.libreswan.org/

PATCH_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/commit/
PATCHFILES=	e43bc147e1342df55f51df06ef886749111d2cff.patch:-p1 # fix for https://github.com/libreswan/libreswan/issues/448
PATCHFILES+=	607237df81c9896743f9b2cb91faab01e4d1c3fc.patch:-p1 # BSD patches: https://github.com/libreswan/libreswan/commit/607237df81c9896743f9b2cb91faab01e4d1c3fc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	IPsec and IKE based firewall

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libevent.so:devel/libevent \
		libldns.so:dns/ldns \
		libnspr4.so:devel/nspr \
		libnss3.so:security/nss \
		libunbound.so:dns/unbound

USES=		bison gmake pkgconfig python

CFLAGS+=	-I${WRKSRC}/include/unbound
LDFLAGS+=	-lcrypt

MAKE_ARGS=	PKG_BASE=${LOCALBASE} \
		NSS_CFLAGS="`pkg-config --cflags nss`" NSPR_LDFLAGS="`pkg-config --libs nss`" \
		USE_PTHREAD_SETSCHEDPRIO=false \
		WERROR_CFLAGS=""  \
		PYTHON_BINARY=${PYTHON_CMD}

OPTIONS_DEFINE=	DOCS

post-configure:
	@cd ${WRKSRC}/mk/defaults && \
		${RLN} netbsd.mk freebsd.mk

post-install:
.for f in _import_crl addconn algparse cavp dncheck ecdsasigkey enumcheck hunkcheck ipcheck jambufcheck keyidcheck pluto readwriteconf rsasigkey showhostkey timecheck whack
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/ipsec/${f}
.endfor

.include <bsd.port.mk>
