# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openpgm
DISTVERSIONPREFIX=	release-
DISTVERSION=	5-2-122
PORTREVISION=	4
CATEGORIES=	net devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implementation of the PGM reliable multicast protocol

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	steve-o

GNU_CONFIGURE=	yes
USES=		autoreconf compiler:c11 pathfix perl5 libtool python:build
USE_PERL5=	build
USE_LDCONFIG=	yes
WRKSRC_SUBDIR=	openpgm/pgm
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS EXAMPLES
PORTDOCS=	draft-ietf-rmt-bb-pgmcc-03.txt rfc3208.txt
PORTEXAMPLES=	*

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/../doc/,} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
