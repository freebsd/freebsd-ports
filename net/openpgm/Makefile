PORTNAME=	openpgm
DISTVERSIONPREFIX=	release-
DISTVERSION=	5-3-128
CATEGORIES=	net devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implementation of the PGM reliable multicast protocol
WWW=		https://code.google.com/p/openpgm/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf compiler:c11 pathfix perl5 libtool python:build
USE_GITHUB=	yes
GH_ACCOUNT=	steve-o
USE_LDCONFIG=	yes
USE_PERL5=	build

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

WRKSRC_SUBDIR=	openpgm/pgm

PORTDOCS=	draft-ietf-rmt-bb-pgmcc-03.txt rfc3208.txt
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-extract:
	${MV} ${WRKSRC}/openpgm-5.2.pc.in ${WRKSRC}/openpgm-5.3.pc.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/../doc/,} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
