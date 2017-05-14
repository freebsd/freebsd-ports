# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openpgm
DISTVERSIONPREFIX=	release-
DISTVERSION=	5-2-122
PORTREVISION=	2
CATEGORIES=	net devel

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Implementation of the PGM reliable multicast protocol

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_powerpc64=	fails to compile: socket.c: internal compiler error: in extract_insn, at recog.c

USE_GITHUB=	yes
GH_ACCOUNT=	steve-o

GNU_CONFIGURE=	yes
USES=		autoreconf pathfix perl5 libtool python:build
USE_LDCONFIG=	yes
WRKSRC_SUBDIR=	openpgm/pgm
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
