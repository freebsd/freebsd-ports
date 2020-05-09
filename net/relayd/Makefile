# $FreeBSD$

PORTNAME=	relayd
PORTVERSION=	5.5.20140810
PORTREVISION=	6
CATEGORIES=	net

MAINTAINER=	koue@chaosophia.net
COMMENT=	OpenBSD relay daemon

LICENSE=	ISCL

GH_ACCOUNT=	mmatuska

USES=		ssl uidfix
USE_GITHUB=	yes
USE_RC_SUBR=	relayd
WRKSRC_SUBDIR=	src/usr.sbin

CFLAGS+=	-Wall

MAKE_ARGS+=	BINDIR=${PREFIX}/sbin \
		MANDIR=${PREFIX}/man/man

USERS=		_relayd
GROUPS=		_relayd

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/relayd/relay.c \
		${WRKSRC}/relayd/relayd.h \
		${WRKSRC}/relayd/relayd.conf.5 \
		${WRKSRC}/relayd/relayd.8

post-install:
	@${INSTALL_DATA} ${WRKSRC}/../etc/relayd.conf \
		${STAGEDIR}${PREFIX}/etc/relayd.conf.sample

.include <bsd.port.pre.mk>

.if ! ${SSL_DEFAULT:Mlibressl*}
. ifnmake describe
STAGEDIR_libressl!=	${MAKE} -V STAGEDIR -C ${PORTSDIR}/security/libressl
. endif
BUILD_DEPENDS+=	${NONEXISTENT}:security/libressl:stage
.endif # SSL_DEFAULT

CFLAGS+=	-I${STAGEDIR_libressl}${LOCALBASE}/include

post-configure:
	${REINPLACE_CMD} 's|-lssl|${STAGEDIR_libressl}${LOCALBASE}/lib/libssl.a|g' \
		 ${WRKSRC}/relayd/Makefile
	${REINPLACE_CMD} 's|-lcrypto|${STAGEDIR_libressl}${LOCALBASE}/lib/libcrypto.a|g' \
		${WRKSRC}/relayd/Makefile

.include <bsd.port.post.mk>
