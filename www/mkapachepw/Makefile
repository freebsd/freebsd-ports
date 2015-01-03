# Created by: tundra
# $FreeBSD$

PORTNAME=	mkapachepw
PORTVERSION=	1.121
CATEGORIES=	www
MASTER_SITES=	http://www.tundraware.com/Software/mkapachepw/

MAINTAINER=	mkapachepw@tundraware.com
COMMENT=	Group & Password Management Tool For Apache

USES=		python
OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in WHATSNEW.txt mkapachepw-license.txt mkapachepw.html mkapachepw.pdf mkapachepw.ps mkapachepw.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
