# New ports collection makefile for:	openvswitch
# Date created:		2011-11-01
# Whom:			Edward Tomasz Napierala <trasz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openvswitch
DISTVERSION=	1.1.0pre2
CATEGORIES=	net
MASTER_SITES=	http://openvswitch.org/releases/
#MASTER_SITE_SUBDIR=
#PKGNAMEPREFIX=
#PKGNAMESUFFIX=
#DISTNAME=
#EXTRACT_SUFX=
#DISTFILES=
#DIST_SUBDIR=	${PORTNAME}
#EXTRACT_ONLY=

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	A production quality, multilayer virtual switch

LICENSE=	ASL

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	SSL_LIBS=-lssl SSL_CFLAGS=-I/usr/include/openssl
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf automake
USE_GNOME=	pkgconfig
USE_PYTHON=	yes
USE_RC_SUBR=	ovs-vswitchd ovsdb-server
MAN1=		ovsdb-tool.1 ovsdb-client.1 ovsdb-server.1
MAN5=		ovs-vswitchd.conf.db.5
MAN8=		ovs-appctl.8 ovs-controller.8 ovs-discover.8 ovs-dpctl.8 \
		ovs-kill.8 ovs-ofctl.8 ovs-openflowd.8 ovs-parse-leaks.8 \
		ovs-pki.8 ovs-vsctl.8 ovs-vswitchd.8 ovs-brcompatd.8

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
BROKEN=		does not compile
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/vswitchd/vswitch.ovsschema ${PREFIX}/share/openvswitch/

.include <bsd.port.post.mk>
