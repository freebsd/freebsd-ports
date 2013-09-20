# Created by: wosch
# $FreeBSD$

PORTNAME=	socket
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	sysutils net ipv6
MASTER_SITES=	http://wolfram.schneider.org/src/

MAINTAINER=	wosch@FreeBSD.org
COMMENT=	Create TCP socket and connect to stdin/out

MAKE_ENV+=	SWITCHES="-DUSE_INET6 -DHAVE_SYS_PARAM_H -Wall"
MAN1=		socket.1

NO_STAGE=	yes
post-install:
	@${MKDIR} ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/

.include <bsd.port.mk>
