# Created by: Sylvio Cesar <sylvio@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jailkit
PORTVERSION=	2.15
PORTREVISION=	3
CATEGORIES=	shells
MASTER_SITES=	http://olivier.sessink.nl/jailkit/ \
		http://www.sfr-fresh.com/unix/privat/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utilities to limit user account

LICENSE=	BSD3CLAUSE

USES=		python:2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PYTHONINTERPRETER=${PYTHON_CMD}

PORTDOCS=	COPYRIGHT README.txt

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
