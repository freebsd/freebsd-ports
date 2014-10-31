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
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS EXAMPLES
DOCS_DESC=	Install documetation
EXAMPLES_DESC=	Install examples

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/../doc/draft-ietf-rmt-bb-pgmcc-03.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/../doc/rfc3208.txt ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} examples ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
