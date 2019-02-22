# Created by: Vasil Dimov <vd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qtum
PORTVERSION=	0.17.2
DISTVERSIONPREFIX=	mainnet-ignition-v
CATEGORIES=	net-p2p finance

MAINTAINER=	vd@FreeBSD.org
COMMENT=	PoS cryptocurrency that can execute smart contract as part of an UTXO

LICENSE=	GPLv3

BROKEN_i386=	does not compile: invalid operand for instruction ... ASJ(jnz, 0, b) ... "jnz"

BUILD_DEPENDS=	libzmq4>0:net/libzmq4
RUN_DEPENDS=	libzmq4>0:net/libzmq4
LIB_DEPENDS=	libboost_date_time.so:devel/boost-libs \
		libevent.so:devel/libevent \
		libminiupnpc.so:net/miniupnpc \
		libprotobuf.so:devel/protobuf \
		libqrencode.so:graphics/libqrencode

USES=		autoreconf bdb:5+ compiler:c++14-lang gmake libtool pkgconfig qt:5 ssl

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	BDB_CFLAGS="-I${BDB_INCLUDE_DIR}" \
		BDB_LIBS="-L${BDB_LIB_DIR} -l${BDB_LIB_CXX_NAME}"
# * Man pages have not been adjusted after cloning the Bitcoin code base.
#   They are the old Bitcoin man pages, so do not install them.
# * --with-incompatible-bdb is required in order to use bdb-5.
# * Do not install unneeded include/bitcoinconsensus.h and
#   lib/libbitcoinconsensus.* (--without-libs)
CONFIGURE_ARGS=	--disable-man \
		--with-gui=qt5 \
		--with-incompatible-bdb \
		--with-miniupnpc=${LOCALBASE} \
		--with-qrencode \
		--without-libs

USE_QT=		buildtools core dbus gui linguisttools network testlib widgets
USE_GITHUB=	yes
GH_TUPLE=	qtumproject:qtum:${DISTVERSIONPREFIX}${PORTVERSION} \
		qtumproject:cpp-eth-qtum:d6081ecc98e3c5f4701363:cppeth/src/cpp-ethereum

.include <bsd.port.pre.mk>

# The ./configure script tries to use pkg-config to derive the SSL CFLAGS and
# libraries, but pkg-config requires libssl.pc which is only installed by the
# ports' security/openssl and not present in the base system. So if we are to
# use the base's SSL, then we trick ./configure to not use pkg-config by
# setting some related environment variables.
.if ${SSL_DEFAULT} == base
CONFIGURE_ENV+=	CRYPTO_CFLAGS="-I${OPENSSLINC}" \
		CRYPTO_LIBS="-L${OPENSSLLIB} -lcrypto" \
		SSL_CFLAGS="-I${OPENSSLINC}" \
		SSL_LIBS="-L${OPENSSLLIB} -lssl"
.endif

.include <bsd.port.post.mk>
