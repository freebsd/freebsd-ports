PORTNAME=	relayd
DISTVERSION=	7.3.2023.05.09-p5
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://github.com/KlaraSystems/freebsd-relayd/releases/download/${DISTVERSION}/

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	OpenBSD relay daemon
WWW=		https://github.com/KlaraSystems/freebsd-relayd

LICENSE=	ISCL

LIB_DEPENDS=	libpfctl.so:net/libpfctl

USES=		localbase:ldflags ssl uidfix
USE_RC_SUBR=	relayd

HAS_CONFIGURE=	yes

LDFLAGS+=	-lpfctl

USERS=		_relayd
GROUPS=		_relayd

.include <bsd.port.pre.mk>

.if !${SSL_DEFAULT:Mlibressl*}
_LIBRESSL_ORIGIN=	security/libressl
. ifnmake describe
STAGEDIR_libressl!=	${MAKE} -V STAGEDIR -C ${PORTSDIR}/${_LIBRESSL_ORIGIN}
. endif
BUILD_DEPENDS+=		${NONEXISTENT}:${_LIBRESSL_ORIGIN}:stage
.endif # SSL_DEFAULT

MAKE_ENV=	LIBCRYPTO=${STAGEDIR_libressl}${LOCALBASE}/lib/libcrypto.a \
		LIBSSL=${STAGEDIR_libressl}${LOCALBASE}/lib/libssl.a \
		LIBTLS=${STAGEDIR_libressl}${LOCALBASE}/lib/libtls.a \
		OPENSSLINCDIR=${STAGEDIR_libressl}${LOCALBASE}/include

post-patch:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/usr.sbin/relayd/relayd.conf.5 \
		${WRKSRC}/usr.sbin/relayd/relayd.8

do-install:
	${INSTALL_DATA} ${WRKSRC}/etc/examples/relayd.conf \
		${STAGEDIR}${PREFIX}/etc/relayd.conf.sample
	${INSTALL_MAN} ${WRKSRC}/usr.sbin/relayctl/relayctl.8 \
		${STAGEDIR}${PREFIX}/share/man/man8/
	${INSTALL_MAN} ${WRKSRC}/usr.sbin/relayd/relayd.8 \
		${STAGEDIR}${PREFIX}/share/man/man8/
	${INSTALL_MAN} ${WRKSRC}/usr.sbin/relayd/relayd.conf.5 \
		${STAGEDIR}${PREFIX}/share/man/man5/
	${INSTALL_PROGRAM} ${WRKSRC}/usr.sbin/relayctl/relayctl \
		${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/usr.sbin/relayd/relayd \
		${STAGEDIR}${PREFIX}/sbin/

.include <bsd.port.post.mk>
