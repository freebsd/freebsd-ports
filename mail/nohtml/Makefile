# Created by: nohtml@tundraware.com
# $FreeBSD$

PORTNAME=	nohtml
PORTVERSION=	1.11
CATEGORIES=	mail
MASTER_SITES=	http://www.tundraware.com/Software/nohtml/

MAINTAINER=	nohtml@tundraware.com
COMMENT=	Strip HTML attachments from email

USE_PYTHON=	yes

MANCOMPRESSED=	yes
MAN1=		nohtml.1

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in nohtml-license.txt nohtml.html nohtml.pdf nohtml.ps nohtml.txt
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
