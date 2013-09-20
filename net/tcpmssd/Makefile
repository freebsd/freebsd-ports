# Created by: ru
# $FreeBSD$

PORTNAME=	tcpmssd
PORTVERSION=	1.1
CATEGORIES=	net
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A utility to correct requested TCP receive segment size

WRKSRC=		${WRKDIR}/src

SRC=		${.CURDIR}/src

MAN8=		tcpmssd.8
PLIST_FILES=	bin/tcpmssd

NO_STAGE=	yes
do-fetch:
	@${DO_NADA}

pre-patch:
	@${CP} -R ${SRC} ${WRKDIR}

do-build:
	(cd ${WRKSRC} && ${MAKE} tcpmssd)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpmssd ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tcpmssd.8 ${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
