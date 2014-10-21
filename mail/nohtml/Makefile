# Created by: nohtml@tundraware.com
# $FreeBSD$

PORTNAME=	nohtml
PORTVERSION=	1.11
CATEGORIES=	mail
MASTER_SITES=	http://www.tundraware.com/Software/nohtml/

MAINTAINER=	nohtml@tundraware.com
COMMENT=	Strip HTML attachments from email

USES=		python

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in nohtml-license.txt nohtml.html nohtml.pdf nohtml.ps nohtml.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
