# Created by: tundra
# $FreeBSD$

PORTNAME=	mkapachepw
PORTVERSION=	1.121
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.tundraware.com/Software/mkapachepw/

MAINTAINER=	mkapachepw@tundraware.com
COMMENT=	Group & Password Management Tool For Apache

USES=		python:2.7,run shebangfix
SHEBANG_FILES=	mkapachepw.py
NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in WHATSNEW.txt mkapachepw-license.txt mkapachepw.html mkapachepw.pdf mkapachepw.ps mkapachepw.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
