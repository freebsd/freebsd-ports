# Created by: dave@dogwood.com
# $FreeBSD$

PORTNAME=	olsrd
DISTVERSION=	0.6.6.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.olsr.org/releases/0.6/ \
		http://ftp2.za.freebsd.org/pub/mesh/pc/protocols/olsr/

MAINTAINER=	jhay@FreeBSD.org
COMMENT=	OLSR routing daemon

BUILD_DEPENDS=	makedepend:${PORTSDIR}/devel/makedepend

USES=		bison gmake tar:bzip2
USE_LDCONFIG=	yes
USE_RC_SUBR=	olsrd

ALL_TARGET=	build_all
INSTALL_TARGET=	install_all

OPTIONS_DEFINE=	MULTI_IF
MULTI_IF_DESC=	IPv6 multiple interface support

MULTI_IF_LIB_DEPENDS=	libnet.so:${PORTSDIR}/net/libnet
MULTI_IF_MAKE_ARGS=	LIBNET=1

.if defined(PREFIX)
MAKE_ARGS+=	PREFIX=${PREFIX}
.endif
MAKE_ARGS+=	STAGEDIR=${STAGEDIR}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/sbin/ldconfig|:|g' ${WRKSRC}/make/Makefile.fbsd

post-install:
	@${ECHO_MSG}	""
	@${ECHO_MSG}	" Set olsrd_enable=\"YES\" in /etc/rc.conf to enable"
	@${ECHO_MSG}	""

.include <bsd.port.post.mk>
