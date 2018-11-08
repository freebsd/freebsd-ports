# Created by: Dan Langille <dan@langille.org>
# $FreeBSD$

PORTNAME=	bacula
PKGNAMESUFFIX=	-bat

COMMENT=	Network backup solution (GUI)

DEPRECATED=	Unsupported. Please migrate to bacula9-bat
EXPIRATION_DATE=	2019-03-01

LIB_DEPENDS+=	libqwt.so:x11-toolkits/qwt5 \
		libbac.so:sysutils/bacula-client

USES=		pkgconfig qt:4
USE_QT=		qmake_build uic_build moc_build rcc_build
WITH_BAT=	yes

PLIST=		${.CURDIR}/pkg-plist
MAKE_ENV+=	MAKEOBJDIRPREFIX=/

MASTERDIR=	${.CURDIR}/../../sysutils/bacula-server

CONFIGURE_ARGS+=	--enable-bat \
			--with-qwt=${LOCALBASE}/lib \
			--disable-build-dird \
			--disable-build-stored \
			--enable-client-only

OPTIONS_DEFINE=	#
OPTIONS_DEFAULT=#

.include "${MASTERDIR}/Makefile"
