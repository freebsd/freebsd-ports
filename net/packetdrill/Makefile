# $FreeBSD$

PORTNAME=	packetdrill
PORTVERSION=	0.0.2020082101
CATEGORIES=	net

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	Network stack testing tool

LICENSE=	GPLv2

BROKEN_FreeBSD_11=	TCP Fast Open struct changes

USES=		bison python:run uidfix
USE_GITHUB=	yes
GH_ACCOUNT=	freebsd-net
GH_TAGNAME=	f7cbdaa
WRKSRC_SUBDIR=	gtests/net/packetdrill
PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	packetdrill.el packetdrill.vim
PORTDOCS=	README
PORTEXAMPLES=	tests

OPTIONS_DEFINE=	DOCS EXAMPLES

# XXX Static libraries with PIE are currently unsupported.
MAKE_ARGS+=	WITHOUT_PIE=true

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
