PORTNAME=	diskroaster
DISTVERSION=	1.1.1
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/favoritelotus/diskroaster/releases/download/v${DISTVERSION}/

MAINTAINER=     pavel.golubinsky@gmail.com
COMMENT=        Multithreaded disk tester that writes and verifies data on raw devices
WWW=		https://github.com/favoritelotus/diskroaster

LICENSE=	BSD3CLAUSE

USES=		tar:bzip2
MAKE_ENV=    	CC="${CC}" CFLAGS="${CFLAGS}" LIBS="-pthread" PREFIX="${PREFIX}"

PLIST_FILES=    sbin/${PORTNAME}\
		share/man/man8/${PORTNAME}.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin/
	${GZIP_CMD} -f ${WRKSRC}/man/${PORTNAME}.8.freebsd
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.8.freebsd.gz \
		${STAGEDIR}${PREFIX}/share/man/man8/${PORTNAME}.8.gz

.include <bsd.port.mk>
