# $FreeBSD$

PORTNAME=	erlang_xmlrpc
PORTVERSION=	1.13
PORTREVISION=	12
CATEGORIES=	net
MASTER_SITES=	http://www.erlang.org/contrib/
DISTNAME=	xmlrpc-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	erlang

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A library for XMLRPC support in Erlang

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang

PLIST_SUB=      VERSION="${PORTVERSION}"

USES=		gmake
WRKSRC=		${WRKDIR}/xmlrpc-${PORTVERSION}

PORTDOCS=	*

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|XMERL_PATH=.*|XMERL_PATH=${LOCALBASE}/lib/erlang/lib/xmerl|g' ${WRKSRC}/src/Makefile
	@${RM} ${WRKSRC}/src/Makefile.bak ${WRKSRC}/src/*.orig

do-build:
	@cd ${WRKSRC}/src && ${GMAKE}

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	for FILE in xmlrpc.pdf xmlrpc.ps xmlrpc.txt; do \
		${INSTALL_DATA} ${WRKSRC}/doc/$${FILE} ${STAGEDIR}${DOCSDIR}; \
	done
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/xmlrpc-${PORTVERSION}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/xmlrpc-${PORTVERSION}/ebin
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/xmlrpc-${PORTVERSION}/src
	${INSTALL_DATA} ${WRKSRC}/ebin/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/xmlrpc-${PORTVERSION}/ebin
	${INSTALL_DATA} ${WRKSRC}/src/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/xmlrpc-${PORTVERSION}/src
	${INSTALL_MAN} ${WRKSRC}/doc/xmlrpc.3 ${STAGEDIR}${MANPREFIX}/man/man3/erlang_xmlrpc.3

.include <bsd.port.mk>
