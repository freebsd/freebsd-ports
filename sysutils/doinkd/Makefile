# Created by: Andrew <andrew@ugh.net.au>, Iain Templeton <iain@ugh.net.au>
# $FreeBSD$

PORTNAME=	doinkd
PORTVERSION=	0.01
PORTREVISION=	6
CATEGORIES=	sysutils
MASTER_SITES=	SF/idled/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Daemon that logs out idle users and those users hogging resources

USE_RC_SUBR=	${PORTNAME}

MAKE_ARGS=	STAGEDIR=${STAGEDIR}

post-extract:
	(cd ${WRKSRC}; make clean)

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/doinkd

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/doinkd

.include <bsd.port.mk>
