# $FreeBSD$

PORTNAME=	packetdrill
PORTVERSION=	0.0.1
CATEGORIES=	net ipv6
DISTNAME=	${PORTNAME}-467b39b

MAINTAINER=	gnn@freebsd.org
COMMENT=	Network stack testing tool

LICENSE=	GPLv2

USES=		bison
PORTDATA=	packetdrill.el packetdrill.vim
PORTDOCS=	README
PORTEXAMPLES=	tests

OPTIONS_DEFINE=	DOCS EXAMPLES

USE_GITHUB=	yes
GH_ACCOUNT=	freebsd-net
GH_PROJECT=	packetdrill
GH_TAGNAME=	467b39b

GNU_CONFIGURE=	yes

WRKSRC_SUBDIR=	gtests/net/packetdrill

do-install:
.for f in packetdrill checksum_test packet_parser_test packet_to_string_test
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/contrib && ${INSTALL_DATA} ${PORTDATA} \
	    ${STAGEDIR}${DATADIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${PORTEXAMPLES} \
	    ${STAGEDIR}${EXAMPLESDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
