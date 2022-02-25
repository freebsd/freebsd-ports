PORTNAME=	relayd
PORTVERSION=	5.5.20140810
PORTREVISION=	8
CATEGORIES=	net

MAINTAINER=	koue@chaosophia.net
COMMENT=	OpenBSD relay daemon

LICENSE=	ISCL

USES=		ssl uidfix
USE_GITHUB=	yes
GH_ACCOUNT=	mmatuska

USE_RC_SUBR=	relayd
MAKE_ARGS+=	BINDIR=${PREFIX}/sbin \
		MANDIR=${PREFIX}/man/man

CFLAGS+=	-Wall

WRKSRC_SUBDIR=	src/usr.sbin

USERS=		_relayd
GROUPS=		_relayd

post-install:
	${INSTALL_DATA} ${WRKSRC}/../etc/relayd.conf \
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
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/relayd/relay.c \
		${WRKSRC}/relayd/relayd.h \
		${WRKSRC}/relayd/relayd.conf.5 \
		${WRKSRC}/relayd/relayd.8
	${REINPLACE_CMD} 's|-lssl|${STAGEDIR_libressl}${LOCALBASE}/lib/libssl.a|g' \
		 ${WRKSRC}/relayd/Makefile
	${REINPLACE_CMD} 's|-lcrypto|${STAGEDIR_libressl}${LOCALBASE}/lib/libcrypto.a|g' \
		${WRKSRC}/relayd/Makefile

.include <bsd.port.post.mk>
