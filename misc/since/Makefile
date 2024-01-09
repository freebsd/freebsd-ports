PORTNAME=	since
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://welz.org.za/projects/since/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	View the end of a file like tail(1), but save state between sessions
WWW=		http://welz.org.za/projects/since

LICENSE=	GPLv3

USES=		gmake

ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/since share/man/man1/since.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/since ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/since.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
