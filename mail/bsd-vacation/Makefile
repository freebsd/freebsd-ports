PORTNAME=	bsd-vacation
DISTVERSIONPREFIX=	v
DISTVERSION=		1.0.1
CATEGORIES=	mail

MAINTAINER=	gbe@FreeBSD.org
COMMENT=	This is a port of the vacation(1) command based on the BSD4.3 version
WWW=		https://github.com/gbergling/bsd-vacation

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	gbergling

PLIST_FILES=	bin/vacation share/man/man1/vacation.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vacation ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/vacation.1.gz ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
