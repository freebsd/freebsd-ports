PORTNAME=	squid-langpack
DISTVERSION=	7.0.0-${SLP_DATE}
CATEGORIES=	www
MASTER_SITES=	http://www2.pl.squid-cache.org/Versions/langpack/ \
		http://www1.il.squid-cache.org/Versions/langpack/ \
		http://www1.jp.squid-cache.org/Versions/langpack/ \
		http://www2.gr.squid-cache.org/Versions/langpack/ \
		http://ca2.squid-cache.org/Versions/langpack/ \
		http://www.squid-cache.org/Versions/langpack/
DISTNAME=	${PORTNAME}-${SLP_DATE}

MAINTAINER=	otis@FreeBSD.org
COMMENT=	Language-specific error documents for Squid web cache
WWW=		http://www.squid-cache.org/Versions/langpack

LICENSE=	GPLv2

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

PORTDOCS=	COPYRIGHT TRANSLATORS
PORTEXAMPLES=	alias-link.sh aliases templates

OPTIONS_DEFINE=		DOCS EXAMPLES
OPTIONS_DEFAULT=	DOCS EXAMPLES

# On updating the port, set this variable to the date requested
SLP_DATE=	20240307
SLP_LANGS=	af ar az bg ca cs da de el en es es-mx et fa fi fr he hu hy id \
		it ja ka ko lt lv ms nl oc pl pt pt-br ro ru sk sl sr-cyrl \
		sr-latn sv th tr uk uz vi zh-hans zh-hant

do-extract:
	${MKDIR} ${WRKSRC}
	${TAR} xzf ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} -C ${WRKSRC}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
.for lang in ${SLP_LANGS}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} ${lang} ${STAGEDIR}${DATADIR})
.endfor

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} ${doc} ${STAGEDIR}${DOCSDIR})
.endfor

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for example in ${PORTEXAMPLES}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} ${example} ${STAGEDIR}${EXAMPLESDIR})
.endfor

.include <bsd.port.mk>
