PORTNAME=	diskroaster
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.0
CATEGORIES=	sysutils

MAINTAINER=	pavel.golubinsky@gmail.com
COMMENT=	Multithreaded disk tester that writes and verifies data on raw devices
WWW=		https://github.com/favoritelotus/diskroaster

LICENSE=	BSD3CLAUSE

USES=		tar:bzip2
USE_GITHUB=	yes
GH_ACCOUNT=	favoritelotus

MAKE_ENV=	CC="${CC}" CFLAGS="${CFLAGS}" LIBS="-pthread" PREFIX="${PREFIX}"

PLIST_FILES=	sbin/${PORTNAME}\
		share/man/man8/${PORTNAME}.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.8.freebsd \
		${STAGEDIR}${PREFIX}/share/man/man8/${PORTNAME}.8

.include <bsd.port.mk>
