# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openpgm
PORTVERSION=	5.2.122
PORTREVISION=	2
CATEGORIES=	net devel
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	libpgm-${PORTVERSION}

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Implementation of the PGM reliable multicast protocol

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		pathfix perl5 tar:bzip2 libtool python:build
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/openpgm/pgm
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS EXAMPLES
PORTDOCS=	draft-ietf-rmt-bb-pgmcc-03.txt rfc3208.txt
PORTEXAMPLES=	*

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/../doc/,} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
