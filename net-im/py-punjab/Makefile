# Created by: jodocus <jodocus@jodocus.org>
# $FreeBSD$

PORTNAME=	punjab
PORTVERSION=	0.14
PORTREVISION=	2
CATEGORIES=	net-im python
MASTER_SITES=	http://code.stanziq.com/punjab/releases/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTTP XMPP client interface

USE_PYTHON=	distutils autoplist
USES=		python twisted:words,web,conch,names

PORTDOCS=	README.txt INSTALL.txt PKG-INFO

USE_RC_SUBR=	punjab

SUB_FILES=	pkg-message punjab.tac
SUB_LIST+=	"PYTHON_CMD=${PYTHON_CMD}"

post-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC}/html && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	${INSTALL} ${WRKDIR}/punjab.tac ${STAGEDIR}${PREFIX}/libexec/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
