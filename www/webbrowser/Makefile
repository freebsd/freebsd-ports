PORTNAME=	webbrowser
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Wrapper for running the "best" available WEB browser
WWW=		http://personalpages.tds.net/~jwbacon/Ports

LICENSE=	BSD2CLAUSE

NO_BUILD=	yes
USES=		tar:xz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/webbrowser ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/webbrowser.1 ${STAGEDIR}${PREFIX}/share/man/man1

PLIST_FILES=	bin/webbrowser share/man/man1/webbrowser.1.gz

.include <bsd.port.mk>
