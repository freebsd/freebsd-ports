# New ports collection makefile for:	strongswan
# Date created:				30 May 2010
# Whom:					<riaank@gmail.com>
#
# $FreeBSD$

PORTNAME=	strongswan
PORTVERSION=	4.4.0
CATEGORIES=	security
MASTER_SITES=	http://download.strongswan.org/ \
		http://download2.strongswan.org/

MAINTAINER=	riaank@gmail.com
COMMENT=	Open Source IPSec-based VPN solution

LIB_DEPENDS=	vstr:${PORTSDIR}/devel/vstr \
		gmp.10:${PORTSDIR}/math/gmp

USE_BZIP2=	yes

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-kernel-pfkey \
		--enable-kernel-pfroute  \
		--disable-kernel-netlink  \
		--enable-vstr  \
		--disable-tools  \
		--disable-scripts  \
		--disable-pluto  \
		--with-group=wheel  \
		--with-lib-prefix=${PREFIX}

MAN3=		anyaddr.3 atoaddr.3 atoasr.3 atosa.3 atoul.3 goodmask.3 \
		initaddr.3 initsubnet.3 keyblobtoid.3 portof.3 prng.3 \
		rangetosubnet.3 sameaddr.3 subnetof.3 ttoaddr.3 ttodata.3 \
		ttosa.3 ttoul.3
MAN5=		ipsec.conf.5
MAN8=		ipsec.8 starter.8 _copyright.8 _updown.8 _updown_espmark.8

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
IGNORE=		requires at least FreeBSD 8.X
.endif

.include <bsd.port.post.mk>
