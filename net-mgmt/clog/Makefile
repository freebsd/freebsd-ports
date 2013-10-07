# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD$

PORTNAME=	clog
PORTVERSION=	1.6
CATEGORIES=	net-mgmt security
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	obrien

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	Tcp connection logger daemon

PATCH_DEPENDS=	rcsdiff:${PORTSDIR}/devel/rcs

WRKSRC=		${WRKDIR}/clog
ALL_TARGET=	freebsd
MAN8=		clog.8

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/clog ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/clog.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
