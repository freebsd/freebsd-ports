# Created by: Anders Troback
# $FreeBSD$

PORTNAME=	bacula
CATEGORIES=	net-mgmt
PKGNAMEPREFIX=	nagios-check_
PKGNAMESUFFIX=	#

MAINTAINER=	freebsd@troback.com
COMMENT=	Nagios plugin for Bacula

LIB_DEPENDS+=	bac:${PORTSDIR}/sysutils/bacula-client
UNIQUENAME=	${PKGNAMEPREFIX}${PORTNAME}

WITH_NAGIOS_CHECK_ONLY=	yes
MASTERDIR=	${.CURDIR}/../../sysutils/bacula-server

CONFIGURE_ARGS=	--enable-client-only	\
		--disable-build-dird	\
		--disable-build-stored	\
		--disable-nls		\
		--disable-xatt

OPTIONS_DEFINE=	#

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
