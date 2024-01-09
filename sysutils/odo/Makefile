PORTNAME=	odo
PORTVERSION=	0.2.2
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Atomic odometer for the command line
WWW=		https://github.com/atomicobject/odo

LICENSE=	ISCL

USE_GITHUB=	yes
GH_ACCOUNT=	atomicobject

PLIST_FILES=	bin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-test:
	cd ${WRKSRC} && ${SH} ./test_odo

.include <bsd.port.mk>
