# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openpgm
PORTVERSION=	5.2.122
PORTREVISION=	1
CATEGORIES=	net devel
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	libpgm-${PORTVERSION}

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Implementation of the PGM reliable multicast protocol

LICENSE=	LGPL3

GNU_CONFIGURE=	yes
USES=		pathfix perl5 tar:bzip2 libtool python
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/openpgm/pgm

OPTIONS_DEFINE=	DOCS EXAMPLES
DOCS_DESC=	Install documetation
EXAMPLES_DESC=	Install examples

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
PLIST_SUB+=	EXAMPLES=""
.else
PLIST_SUB+=	EXAMPLES="@comment "
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/../doc/draft-ietf-rmt-bb-pgmcc-03.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/../doc/rfc3208.txt ${STAGEDIR}${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} examples ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
