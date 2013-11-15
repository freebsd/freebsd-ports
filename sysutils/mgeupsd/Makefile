# Created by: Andreas Dobloug <andreasd@@ifi.uio.no>
# $FreeBSD$

PORTNAME=	mgeupsd
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/ups

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Monitor a state of MGE Pulsar UPS connected to RS-232 port

USES=		gmake
WRKSRC=		${WRKDIR}/MGE

PLIST_FILES=	man/man8/${PORTNAME}.8.gz sbin/mgeupsd sbin/powerhandler etc/rc.d/mgeupsd.sh
SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e '/^CC=/s:gcc:${CC}:' \
		-e '/^CFLAGS=/s:-Wall -O2:${CFLAGS}:' ${WRKSRC}/Makefile

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/mgeupsd.sh ${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_SCRIPT} ${FILESDIR}/powerhandler ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
