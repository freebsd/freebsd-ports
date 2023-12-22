PORTNAME=	ztop
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.3
CATEGORIES=	sysutils

MAINTAINER=	asomers@FreeBSD.org
COMMENT=	Display ZFS dataset I/O in real time
WWW=		https://github.com/asomers/ztop

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	asomers

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

post-install:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
		${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
