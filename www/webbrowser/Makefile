# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	webbrowser
PORTVERSION=	0.3
CATEGORIES=	www
MASTER_SITES=	http://acadix.biz/Ports/distfiles/ \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Wrapper for running the "best" available WEB browser

LICENSE=	BSD

NO_BUILD=	yes
USE_XZ=		yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/webbrowser ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/webbrowser.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

PLIST_FILES=	bin/webbrowser man/man1/webbrowser.1.gz

.include <bsd.port.mk>
