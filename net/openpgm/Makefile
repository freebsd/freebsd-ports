# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$
# Do not forget fix version openpgm in devel/libxs

PORTNAME=	openpgm
PORTVERSION=	5.2.122
CATEGORIES=	net devel
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	libpgm-${PORTVERSION}

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Implementation of the PGM reliable multicast protocol

LICENSE=	LGPL3

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USES=	pathfix
USE_LDCONFIG=	yes
USE_PERL5=	yes
USE_PYTHON=	yes
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
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/../doc/draft-ietf-rmt-bb-pgmcc-03.txt ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/../doc/rfc3208.txt ${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} examples ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
