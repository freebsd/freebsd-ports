PORTNAME=	clout
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
CATEGORIES=	sysutils

MAINTAINER=	mahdifeyzolahy@gmail.com
COMMENT=	Colorize command standard error output
WWW=		https://github.com/mateofz/clout

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	mateofz

PLIST_FILES=	bin/clout \
		share/man/man1/clout.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/clout ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/clout.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
