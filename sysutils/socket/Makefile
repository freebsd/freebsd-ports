# Created by: wosch
# $FreeBSD$

PORTNAME=	socket
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	sysutils net ipv6
MASTER_SITES=	http://wolfram.schneider.org/src/\
		http://people.freebsd.org/~wosch/src/

MAINTAINER=	wosch@FreeBSD.org
COMMENT=	Create TCP socket and connect to stdin/out

LICENSE=	GPLv1

MAKE_ENV+=	SWITCHES="-DUSE_INET6 -DHAVE_SYS_PARAM_H -Wall"
PLIST_FILES=	bin/socket man/man1/socket.1.gz

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
