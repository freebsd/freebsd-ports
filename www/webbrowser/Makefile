# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	webbrowser
PORTVERSION=	0.3
CATEGORIES=	www
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Wrapper for running the "best" available WEB browser

LICENSE=	BSD2CLAUSE

NO_BUILD=	yes
USES=		tar:xz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/webbrowser ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/webbrowser.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

PLIST_FILES=	bin/webbrowser man/man1/webbrowser.1.gz

.include <bsd.port.mk>
