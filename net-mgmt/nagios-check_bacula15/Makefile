PORTNAME=	bacula
CATEGORIES=	net-mgmt
PKGNAMEPREFIX=	nagios-check_
PKGNAMESUFFIX=	15

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Nagios plugin for Bacula

LIB_DEPENDS+=	libbac.so:sysutils/bacula15-client

PLIST=		${.CURDIR}/pkg-plist
PLIST_FILES=	libexec/nagios/check_bacula
WITH_NAGIOS_CHECK_ONLY=	yes
MASTERDIR=	${.CURDIR}/../../sysutils/bacula15-server

CONFIGURE_ARGS=	--enable-client-only	\
		--disable-build-dird	\
		--disable-build-stored	\
		--disable-nls		\
		--disable-xatt

OPTIONS_DEFINE=	#
OPTIONS_DEFAULT=#

NO_CCACHE=	yes

.include "${MASTERDIR}/Makefile"
