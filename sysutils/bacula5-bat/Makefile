# Created by: Dan Langille <dan@langille.org>
# $FreeBSD$

PORTNAME=	bacula
PKGNAMESUFFIX=	5-bat
PORTREVISION=	6

COMMENT=	Network backup solution (GUI)

LIB_DEPENDS+=	libqwt.so:x11-toolkits/qwt5 \
		libbac.so:sysutils/bacula5-client

CONFLICTS=	bacula-bat-*

USES=		pkgconfig
USE_QT4=	qmake_build uic_build moc_build rcc_build
WITH_BAT=	yes

PLIST=		${.CURDIR}/pkg-plist
MAKE_ENV+=	MAKEOBJDIRPREFIX=/

MASTERDIR=	${.CURDIR}/../../sysutils/bacula5-server

CONFIGURE_ARGS+=	--enable-bat \
			--with-qwt=${LOCALBASE}/lib \
			--disable-build-dird \
			--disable-build-stored \
			--enable-client-only

OPTIONS_DEFINE=	OPENSSL
OPTIONS_DEFAULT=OPENSSL

.include "${MASTERDIR}/Makefile"
