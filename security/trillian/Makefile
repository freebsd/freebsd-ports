PORTNAME=	trillian
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.2
PORTREVISION=	4
CATEGORIES=	security

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	General transparency
WWW=		https://github.com/google/trillian

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.24,modules
USE_RC_SUBR=	trillian_log_server trillian_log_signer

GO_MODULE=	github.com/google/trillian
GO_TARGET=	./cmd/createtree \
		./cmd/deletetree \
		./cmd/trillian_log_server \
		./cmd/trillian_log_signer \
		./cmd/updatetree

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/trillian_log_server.conf \
		${STAGEDIR}${ETCDIR}/trillian_log_server.conf.sample
	${INSTALL_DATA} ${FILESDIR}/trillian_log_signer.conf \
		${STAGEDIR}${ETCDIR}/trillian_log_signer.conf.sample

.include <bsd.port.mk>
