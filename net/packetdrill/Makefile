# $FreeBSD$

PORTNAME=	packetdrill
PORTVERSION=	0.0.20161117
CATEGORIES=	net ipv6

MAINTAINER=	gnn@FreeBSD.org
COMMENT=	Network stack testing tool

LICENSE=	GPLv2

BROKEN_FreeBSD_9=	Fails in lexer

USES=		bison uidfix
USE_GITHUB=	yes
GH_ACCOUNT=	freebsd-net
GH_TAGNAME=	570c391
WRKSRC_SUBDIR=	gtests/net/packetdrill
PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	packetdrill.el packetdrill.vim
PORTDOCS=	README
PORTEXAMPLES=	tests

OPTIONS_DEFINE=	DOCS EXAMPLES

pre-build:
	${INSTALL_DATA} ${FILESDIR}/Makefile ${FILESDIR}/Makefile.inc ${WRKSRC}
.for F in libpd packetdrill
	${MKDIR} ${WRKSRC}/${F}
	${INSTALL_DATA} ${FILESDIR}/Makefile.${F} ${WRKSRC}/${F}/Makefile
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
