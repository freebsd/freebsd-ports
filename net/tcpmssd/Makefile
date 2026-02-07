PORTNAME=	tcpmssd
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to correct requested TCP receive segment size

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/tcpmssd share/man/man8/tcpmssd.8.gz

do-build:
	${CC} ${CFLAGS} ${FILESDIR}/${PORTNAME}.c -o ${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/${PORTNAME}.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
