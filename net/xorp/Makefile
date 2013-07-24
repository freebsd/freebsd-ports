# Created by: Bruce M Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xorp
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.xorp.org/releases/${PORTVERSION}/	\
		http://www2.xorp.org/releases/${PORTVERSION}/	\
		http://www5.xorp.org/releases/${PORTVERSION}/	\
		http://www3.xorp.org/releases/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The eXtensible Open Router Platform

LICENSE=	GPLv2

OPTIONS_DEFINE=	ADVMCAST IPV6 SNMP OPTIMIZED_CFLAGS TEST DEBUG PROFILE
OPTIONS_DEFAULT=	ADVMCAST IPV6 SNMP OPTIMIZED_CFLAGS TEST PROFILE

ADVMCAST_DESC=	Build with Advanced Multicast API

BROKEN=		Does not build

USE_GMAKE=	yes
USE_OPENSSL=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=		--prefix=${PREFIX}/${PORTNAME}			\
			--with-comment='FreeBSD port: ${PKGNAME}'	\
			--with-openssl=${OPENSSLBASE}

CXXFLAGS+=	-Wno-uninitialized
NOMAN=		defined

XORP_GROUP=	xorp
USE_RC_SUBR=	xorp

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MADVMCAST}
CONFIGURE_ARGS+=	--enable-advanced-mcast-api
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if ${PORT_OPTIONS:MSNMP}
BUILD_DEPENDS+=		${LOCALBASE}/sbin/snmpd:${PORTSDIR}/net-mgmt/net-snmp
CONFIGURE_ARGS+=	--with-snmp					 \
	--with-path-to-snmpd=${LOCALBASE}/sbin				 \
	--with-path-to-net-snmpd-config=${LOCALBASE}/bin/net-snmp-config \
	--enable-shared
PLIST_SUB+=		XORP_SNMP=""
USE_LDCONFIG=		${PREFIX}/mibs
.else
PLIST_SUB+=		XORP_SNMP="@comment "
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CONFIGURE_ARGS+=	--enable-optimize --disable-debug
.endif

.if ${PORT_OPTIONS:MTEST}
BUILD_DEPENDS+=	${LOCALBASE}/bin/python:${PORTSDIR}/lang/python \
		${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug-msgs --enable-debug-fnames
.endif

.if ${PORT_OPTIONS:MPROFILE}
CONFIGURE_ARGS+=	--enable-profile
.endif

NOT_FOR_ARCH=	sparc64

.include <bsd.port.pre.mk>

pre-everything::
.if !defined(PREFIX) || ${PREFIX} == "/usr/local"
	@${ECHO_MSG} "XORP does not currently follow the hier(7) filesystem layout."
	@${ECHO_MSG} "It will therefore install all its directories relative to ${PREFIX}."
	@${ECHO_MSG} "If you do not want this, hit ^C now and set PREFIX in the"
	@${ECHO_MSG} "build environment to something other than ${PREFIX}."
	@${ECHO_MSG}
	@${ECHO_MSG} "If you plan to build with SNMP support, please ensure that"
	@${ECHO_MSG} "the net-mgmt/net-snmp port is already installed under ${LOCALBASE}"
	@${ECHO_MSG} "before doing this."
.endif

post-install:
	${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
