# New ports collection makefile for:	xorp
# Date created:		22nd September 2006
# Whom:			Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xorp
PORTVERSION=	1.3
CATEGORIES=	net
MASTER_SITES=	http://www.xorp.org/releases/${PORTVERSION}/	\
		http://www2.xorp.org/releases/${PORTVERSION}/	\
		http://www5.xorp.org/releases/${PORTVERSION}/	\
		http://www3.xorp.org/releases/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	bms@FreeBSD.org
COMMENT=	The eXtensible Open Router Platform

NOMAN=		defined

USE_GMAKE=	yes

#
# XXX: The default prefix needs to be overridden, because the install
# targets create a replica of the XORP build tree containing only
# the binaries and template files, rooted at ${PREFIX}.
#
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=		--prefix=${PREFIX}/xorp \
			--program-prefix="" ${CONFIGURE_TARGET}
CONFIGURE_ENV+=		CXXFLAGS="-Wno-uninitialized"

OPTIONS=								\
	    ADVMCAST	 "Build with Advanced Multicast API" On		\
	    IPV6	 "Build with IPv6 support" On			\
	    SNMP	 "Build with SNMP MIB support (BROKEN)" Off	\
	    OPTIMIZATION "Build with optimization" Off			\
	    CHECK	 "Build with regression test dependencies " Off	\
	    DEBUGGING	 "Enable debugging" Off				\
	    PROFILING	 "Enable profiling" Off

.include <bsd.port.pre.mk>

.if defined(WITH_ADVMCAST)
CONFIGURE_ARGS+=	--enable-advanced-mcast-api
.endif

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

# XXX: The net-snmp MIB tests are currently broken; the MIBs
# will therefore not build.
.if defined(WITH_SNMP)
BUILD_DEPENDS=	${LOCALBASE}/bin/snmpd:${PORTSDIR}/net-mgmt/net-snmp
CONFIGURE_ARGS+=	--with-snmp \
	--with-path-to-snmpd=${LOCALBASE}/bin/snmpd \
	--with-path-to-net-snmpd-config=${LOCALBASE}/bin/net-snmp-config
.endif

.if defined(WITH_OPTIMIZATION)
CONFIGURE_ARGS+=	--enable-optimize
.endif

# Bash and Python are only required if running the regression tests.
.if defined(WITH_CHECK)
BUILD_DEPENDS=	${LOCALBASE}/bin/python:${PORTSDIR}/lang/python \
		${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash2
.endif

.if defined(WITH_DEBUGGING)
CONFIGURE_ARGS+=	--enable-debug-msgs --enable-debug-fnames
.endif

.if defined(WITH_PROFILING)
CONFIGURE_ARGS+=	--enable-profile
.endif

.include <bsd.port.post.mk>
