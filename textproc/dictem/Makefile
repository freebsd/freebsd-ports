PORTNAME=	dictem
PORTVERSION=	1.0.4
PORTREVISION=	25
CATEGORIES=	textproc net elisp
MASTER_SITES=	SF/dictem/dictem/dictem-${PORTVERSION}

MAINTAINER=	max.n.boyarov@gmail.com
COMMENT=	DICT protocol client for [X]Emacs
WWW=		https://sourceforge.net/projects/dictem/

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/bin/dict:textproc/dict

USES=		emacs

CONFLICTS_INSTALL=	dictem-emacs_*

NO_ARCH=	yes
NO_BUILD=	yes

SRC_EL=		dictem.el dictem-lingvo-dsl.el dictem-elisp.el

.for f in ${SRC_EL}
PLIST_FILES+=	${LISPDIR}/${f}
.endfor

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PORTDOCS=	README AUTHORS NEWS COPYING TODO

LISPDIR=	${EMACS_SITE_LISPDIR}/dictem

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${LISPDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${SRC_EL} \
		 ${STAGEDIR}${PREFIX}/${LISPDIR}/)

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
