# New ports collection makefile for:	jabber
# Date created:			5 February 2001
# Whom:				joe
#
# $FreeBSD$
#

PORTNAME=	jabber
PORTVERSION=	1.4.4
PORTEPOCH=	1
CATEGORIES=	net-im ipv6
MASTER_SITES=	http://download.jabberd.org/jabberd14/
DISTNAME=	${PORTNAME}d-${PORTVERSION}
DIST_SUBDIR=	jabber

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Online presence and instant messaging server

LIB_DEPENDS=	pth.20:${PORTSDIR}/devel/pth \
		idn.16:${PORTSDIR}/dns/libidn \
		expat.6:${PORTSDIR}/textproc/expat2

OPTIONS=	IPV6 "Enable IPv6 support" off

USE_GNOME=	gnometarget
USE_RC_SUBR=	jabberd.sh
USE_OPENSSL=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--localstatedir=/var \
		--with-ssl-legacy=/usr
USE_LDCONFIG=	yes

MAN5=		jabber.xml.5
MAN8=		jabberd.8

CPPFLAGS=	-I${LOCALBASE}/include/pth -I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib/pth -L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
