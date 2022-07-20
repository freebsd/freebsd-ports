PORTNAME=	mgeupsd
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	SUNSITE/system/ups

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Monitor a state of MGE Pulsar UPS connected to RS-232 port

DEPRECATED=	Last release is 23 years old. It is not clear what devices are supported.
EXPIRATION_DATE=	2022-07-25

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
