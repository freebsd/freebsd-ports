# New ports collection makefile for:	openvswitch
# Date created:		2011-11-01
# Whom:			Edward Tomasz Napierala <trasz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openvswitch
PORTVERSION=	1.7.0
CATEGORIES=	net
MASTER_SITES=	http://openvswitch.org/releases/

MAINTAINER=	emaste@FreeBSD.org
COMMENT=	A production quality, multilayer virtual switch

LICENSE=	AL2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	SSL_LIBS=-lssl SSL_CFLAGS=-I/usr/include/openssl
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf automake
USE_GNOME=	pkgconfig
USE_PYTHON=	yes
USE_RC_SUBR=	ovs-vswitchd ovsdb-server
MAN1=		ovs-benchmark.1 ovs-pcap.1 ovs-tcpundump.1 ovsdb-client.1 \
		ovsdb-server.1 ovsdb-tool.1
MAN5=		ovs-vswitchd.conf.db.5
MAN8=		ovs-appctl.8 ovs-brcompatd.8 ovs-bugtool.8 ovs-controller.8 \
		ovs-ctl.8 ovs-dpctl.8 ovs-ofctl.8 ovs-parse-leaks.8 ovs-pki.8 \
		ovs-test.8 ovs-vsctl.8 ovs-vswitchd.8 \
		ovs-vlan-bug-workaround.8 ovs-vlan-test.8

OPTIONS_DEFINE=	THREADED
THREADED_DESC=	Experimental high-performance threading patch

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
BROKEN=		does not compile
.endif

.if ${PORT_OPTIONS:MTHREADED}
CONFIGURE_ARGS+=--enable-threaded=yes
.endif

AUTOTOOLSFILES=	aclocal.m4

post-patch:
	@${REINPLACE_CMD} -e 's|1.11.1|%%AUTOMAKE_APIVER%%|g' \
			  -e 's|2.65|%%AUTOCONF_VERSION%%|g' \
			  ${WRKSRC}/aclocal.m4
.if ${PORT_OPTIONS:MTHREADED}
	@# We can't use EXTRA_PATCHES, since we need to apply this one
	@# after files/patch-bsd-netdef.diff, not before.
	${PATCH} ${PATCH_ARGS} < ${FILESDIR}/threaded.diff
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/vswitchd/vswitch.ovsschema ${PREFIX}/share/openvswitch/

.include <bsd.port.post.mk>
