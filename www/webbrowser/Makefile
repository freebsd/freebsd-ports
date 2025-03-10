PORTNAME=	webbrowser
DISTVERSION=	0.4.0
CATEGORIES=	www

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Wrapper for running the "best" available WEB browser
WWW=		https://github.com/outpaddling/webbrowser/

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	outpaddling

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/webbrowser ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/webbrowser.1 ${STAGEDIR}${PREFIX}/share/man/man1

PLIST_FILES=	bin/webbrowser share/man/man1/webbrowser.1.gz

.include <bsd.port.mk>
