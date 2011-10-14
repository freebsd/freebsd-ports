# New ports collection makefile for:	olsrd
# Date created:		6 April 2005
# Whom:			dave@dogwood.com
#
# $FreeBSD$
#

PORTNAME=	olsrd
DISTVERSION=	0.6.2
CATEGORIES=	net
MASTER_SITES=	http://www.olsr.org/releases/0.6/ \
		http://ftp2.za.freebsd.org/pub/mesh/pc/protocols/olsr/

MAINTAINER=	jhay@FreeBSD.org
COMMENT=	OLSR routing daemon

BUILD_DEPENDS=	makedepend:${PORTSDIR}/devel/makedepend

.if defined(WITH_MULTI_IF)
BUILD_DEPENDS+=	libnet*>=1.1.2,1:${PORTSDIR}/net/libnet
.endif

USE_BZIP2=	yes
USE_BISON=	build
USE_GMAKE=	yes

USE_RC_SUBR=	olsrd.sh
MAN8=		olsrd.8
MAN5=		olsrd.conf.5
MANCOMPRESSED=	yes

ALL_TARGET=	build_all
INSTALL_TARGET=	install_all

.if defined(WITH_MULTI_IF)
MAKE_ARGS+=	LIBNET=1
.endif
.if defined(PREFIX)
MAKE_ARGS+=	PREFIX=${PREFIX}
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

.if !defined(WITH_MULTI_IF)
pre-everything::
	@${ECHO_MSG}	""
	@${ECHO_MSG}	" To enable IPv4 multiple interface support make with"
	@${ECHO_MSG}	" WITH_MULTI_IF defined"
	@${ECHO_MSG}	""
.endif

post-install:
	@${ECHO_MSG}	""
	@${ECHO_MSG}	" Set olsrd_enable=\"YES\" in /etc/rc.conf to enable"
	@${ECHO_MSG}	""

.include <bsd.port.post.mk>
