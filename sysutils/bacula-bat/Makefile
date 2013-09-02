# Created by: Dan Langille <dan@langille.org>
# $FreeBSD$

PORTNAME=	bacula
PKGNAMESUFFIX=	-bat
PORTREVISION=	4

COMMENT=	Network backup solution (GUI)

LIB_DEPENDS+=	qwt.5:${PORTSDIR}/x11-toolkits/qwt5 \
		bac:${PORTSDIR}/sysutils/bacula-client

USES=		pkgconfig
USE_QT4=	qmake_build uic_build moc_build rcc_build
WITH_BAT=	yes

MAN1=		bat.1

MAKE_ENV+=	MAKEOBJDIRPREFIX=/

MASTERDIR=	${.CURDIR}/../../sysutils/bacula-server

CONFIGURE_ARGS+=	--enable-bat \
			--with-qwt=${LOCALBASE}/lib \
			--disable-build-dird \
			--disable-build-stored \
			--enable-client-only

OPTIONS_DEFINE=	OPENSSL
OPTIONS_DEFAULT=OPENSSL

.include "${MASTERDIR}/Makefile"
