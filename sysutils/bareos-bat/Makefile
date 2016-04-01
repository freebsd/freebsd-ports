# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bareos
PKGNAMESUFFIX=	-bat
PORTREVISION=	0

COMMENT=	Backup archiving recovery open sourced (GUI)

LIB_DEPENDS+=	libqwt.so:x11-toolkits/qwt5 \
		libbareos.so:sysutils/bareos-client

CONFLICTS=	bacula*-bat-*

USES=		pkgconfig
USE_QT4=	qmake_build uic_build moc_build rcc_build
WITH_BAT=	yes

PLIST=		${.CURDIR}/pkg-plist
MAKE_ENV+=	MAKEOBJDIRPREFIX=/

MASTERDIR=	${.CURDIR}/../../sysutils/bareos-server

CONFIGURE_ARGS+=	--enable-bat \
			--with-qwt=${LOCALBASE}/lib \
			--disable-build-dird \
			--disable-build-stored \
			--enable-client-only

OPTIONS_DEFINE=	OPENSSL
OPTIONS_DEFAULT=OPENSSL

.include "${MASTERDIR}/Makefile"
