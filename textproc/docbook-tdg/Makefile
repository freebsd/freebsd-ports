# Created by: Johann Visagie <wjv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	docbook-tdg
PORTVERSION=	2.0.17
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.docbook.org/tdg/en/
DISTNAME=	tdg-en-html-${PORTVERSION}
DISTFILES=	${DISTNAME} \
		${DISTNAME}-x
EXTRACT_ONLY=	${DISTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Norman Walsh's book "DocBook: The Definitive Guide"

LICENSE=	GFDL

USES=		zip
NO_BUILD=	yes
NO_ARCH=	yes
WRKSRC=		${WRKDIR}/tdg/en

OPTIONS_DEFINE=	UNEXPANDED
UNEXPANDED_DESC=	Unexpanded edition of version 2.0.17

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MUNEXPANDED}
EXTRACT_ONLY=	${DISTNAME}-x
DISTFILES=	${DISTNAME}-x
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/index.html ${STAGEDIR}${DOCSDIR}

post-install:
	${FIND} ${STAGEDIR}${PREFIX} -type f | \
		${SED} 's,${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}

.include <bsd.port.mk>
