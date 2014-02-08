# Created by: ru
# $FreeBSD$

PORTNAME=	tcpmssd
PORTVERSION=	1.1
CATEGORIES=	net
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to correct requested TCP receive segment size

WRKSRC=		${WRKDIR}/src

SRC=		${.CURDIR}/src

PLIST_FILES=	bin/tcpmssd man/man8/tcpmssd.8.gz

pre-patch:
	@${CP} -R ${SRC} ${WRKDIR}

do-build:
	(cd ${WRKSRC} && ${MAKE} tcpmssd)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpmssd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tcpmssd.8 ${STAGEDIR}${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
