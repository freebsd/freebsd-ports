# Created by: Andreas Dobloug <andreasd@@ifi.uio.no>
# $FreeBSD$

PORTNAME=		mgeupsd
PORTVERSION=		0.3
PORTREVISION=	1
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/ups

MAINTAINER=		ports@FreeBSD.org
COMMENT=	Monitor a state of MGE Pulsar UPS connected to RS-232 port

USE_GMAKE=		YES
WRKSRC=			${WRKDIR}/MGE

PLIST_FILES=		sbin/mgeupsd sbin/powerhandler etc/rc.d/mgeupsd.sh
MAN8=			mgeupsd.8
SUB_FILES=		pkg-message

NO_STAGE=	yes
post-patch:
		@${REINPLACE_CMD} -e '/^CC=/s:gcc:${CC}:' \
			-e '/^CFLAGS=/s:-Wall -O2:${CFLAGS}:' ${WRKSRC}/Makefile

post-install:
		${INSTALL_SCRIPT} ${FILESDIR}/mgeupsd.sh ${PREFIX}/etc/rc.d
		${INSTALL_SCRIPT} ${FILESDIR}/powerhandler ${PREFIX}/sbin
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
