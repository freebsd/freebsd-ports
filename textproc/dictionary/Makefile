PORTNAME=	dictionary
PORTVERSION=	1.8.7
PORTREVISION=	41
CATEGORIES=	textproc net elisp
MASTER_SITES=	http://me.in-berlin.de/~myrkr/dictionary/ \
		http://bsdchat.com/dist/dryice/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dictionary client for Emacs
WWW=		https://www.myrkr.in-berlin.de/dictionary/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/GPL

USES=		emacs

LISPDIR=	${PREFIX}/${EMACS_SITE_LISPDIR}/${PORTNAME}
ELS=		connection.el dictionary.el link.el

CONFLICTS_INSTALL=	dictionary-emacs_*

NO_ARCH=	yes
NO_BUILD=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${LISPDIR}
.for i in ${ELS} dictionary-init.el
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${LISPDIR}
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
