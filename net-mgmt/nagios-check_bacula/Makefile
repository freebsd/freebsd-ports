# Created by: Anders Troback
# $FreeBSD$

PORTNAME=	bacula
PORTREVISION=	4
CATEGORIES=	net-mgmt
PKGNAMEPREFIX=	nagios-check_
PKGNAMESUFFIX=	#

MAINTAINER=	freebsd@troback.com
COMMENT=	Nagios plugin for Bacula

DEPRECATED=	Unsupported. Please migrate to nagios-check_bacula9
EXPIRATION_DATE=	2019-03-01

LIB_DEPENDS+=	libbac.so:sysutils/bacula-client

PLIST=		${.CURDIR}/pkg-plist
PLIST_FILES=	libexec/nagios/check_bacula
WITH_NAGIOS_CHECK_ONLY=	yes
MASTERDIR=	${.CURDIR}/../../sysutils/bacula-server

CONFIGURE_ARGS=	--enable-client-only	\
		--disable-build-dird	\
		--disable-build-stored	\
		--disable-nls		\
		--disable-xatt

OPTIONS_DEFINE=	#
OPTIONS_DEFAULT=#

NO_CCACHE=	yes

.include "${MASTERDIR}/Makefile"
