PORTNAME=	openiked
DISTVERSION=	7.4
CATEGORIES=	security net
MASTER_SITES=	https://cdn.openbsd.org/pub/OpenBSD/OpenIKED/ \
		https://github.com/${PORTNAME}/${PORTNAME}-portable/releases/download/v${DISTVERSION}/

MAINTAINER=	marcel@FreeBSD.org
COMMENT=	IKEv2 daemon
WWW=		https://www.openiked.org

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libevent.so:devel/libevent

USES=		cmake ssl

USE_RC_SUBR=	iked
USERS=		_iked
GROUPS=		_iked

CMAKE_ARGS=	-DCMAKE_INSTALL_MANDIR=${PREFIX}/share/man

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/iked.conf \
	    ${STAGEDIR}${PREFIX}/etc/iked.conf.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/ssl/ikeca.cnf \
	    ${STAGEDIR}${PREFIX}/etc/ssl/ikeca.cnf.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/ssl/ikex509v3.cnf \
	    ${STAGEDIR}${PREFIX}/etc/ssl/ikex509v3.cnf.sample

.include <bsd.port.mk>
