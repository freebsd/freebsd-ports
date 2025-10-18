PORTNAME=	extrace
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1
CATEGORIES=	sysutils

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Trace exec() calls system-wide
WWW=		https://github.com/leahneukirchen/extrace-freebsd

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	leahneukirchen
GH_PROJECT=	extrace-freebsd

MAKE_ARGS=	CFLAGS="${CFLAGS}"
CFLAGS+=	-fPIC

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
