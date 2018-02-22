# Created by: nohtml@tundraware.com
# $FreeBSD$

PORTNAME=	nohtml
PORTVERSION=	1.11
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.tundraware.com/Software/nohtml/

MAINTAINER=	nohtml@tundraware.com
COMMENT=	Strip HTML attachments from email

LICENSE=	TundraWare
LICENSE_NAME=	TundraWare license
LICENSE_FILE=	${WRKSRC}/nohtml-license.txt
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell no-auto-accept

USES=		python:2.7,run shebangfix
SHEBANG_FILES=	nohtml.py
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in nohtml.html nohtml.pdf nohtml.ps nohtml.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
