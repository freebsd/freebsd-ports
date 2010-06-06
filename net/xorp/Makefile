# New ports collection makefile for:	xorp
# Date created:		22nd September 2006
# Whom:			Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xorp
PORTVERSION=	1.6
CATEGORIES=	net
MASTER_SITES=	http://www.xorp.org/releases/${PORTVERSION}/	\
		http://www2.xorp.org/releases/${PORTVERSION}/	\
		http://www5.xorp.org/releases/${PORTVERSION}/	\
		http://www3.xorp.org/releases/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The eXtensible Open Router Platform

NOMAN=		defined

USE_GMAKE=	yes

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=		--prefix=${PREFIX}/${PORTNAME}			\
			--with-comment='FreeBSD port: ${PKGNAME}'	\
			--with-openssl=/usr

CONFIGURE_ENV+=		CXXFLAGS="-Wno-uninitialized"

OPTIONS=								\
	    ADVMCAST	 "Build with Advanced Multicast API" On		\
	    IPV6	 "Build with IPv6 support" On			\
	    SNMP	 "Build with SNMP MIB support" Off		\
	    OPTIMIZATION "Build with optimization" On			\
	    CHECK	 "Build with regression test dependencies " Off	\
	    DEBUGGING	 "Enable debugging" Off				\
	    PROFILING	 "Enable profiling" Off

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

.include <bsd.port.pre.mk>

XORP_GROUP=	xorp
USE_RC_SUBR=	xorp

.if defined(WITH_ADVMCAST)
CONFIGURE_ARGS+=	--enable-advanced-mcast-api
.endif

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if defined(WITH_SNMP)
BUILD_DEPENDS=		${LOCALBASE}/sbin/snmpd:${PORTSDIR}/net-mgmt/net-snmp
CONFIGURE_ARGS+=	--with-snmp					 \
	--with-path-to-snmpd=${LOCALBASE}/sbin				 \
	--with-path-to-net-snmpd-config=${LOCALBASE}/bin/net-snmp-config \
	--enable-shared
PLIST_SUB+=		XORP_SNMP=""
USE_LDCONFIG=		${PREFIX}/mibs
.else
PLIST_SUB+=		XORP_SNMP="@comment "
.endif

.if defined(WITH_OPTIMIZATION)
CONFIGURE_ARGS+=	--enable-optimize --disable-debug
.endif

# Bash and Python are only required if running the regression tests.
.if defined(WITH_CHECK)
BUILD_DEPENDS=	${LOCALBASE}/bin/python:${PORTSDIR}/lang/python \
		${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash
.endif

.if defined(WITH_DEBUGGING)
CONFIGURE_ARGS+=	--enable-debug-msgs --enable-debug-fnames
.endif

.if defined(WITH_PROFILING)
CONFIGURE_ARGS+=	--enable-profile
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

post-install:
	${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
