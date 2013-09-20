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

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/xmlrpc-${PORTVERSION}

MAN3=		erlang_xmlrpc.3

PORTDOCS=	*

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|XMERL_PATH=.*|XMERL_PATH=${LOCALBASE}/lib/erlang/lib/xmerl|g' ${WRKSRC}/src/Makefile
	@${RM} ${WRKSRC}/src/Makefile.bak ${WRKSRC}/src/*.orig

do-build:
	@cd ${WRKSRC}/src && ${GMAKE}

do-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@for FILE in xmlrpc.pdf xmlrpc.ps xmlrpc.txt; do \
		${INSTALL_DATA} ${WRKSRC}/doc/$${FILE} ${DOCSDIR}; \
	done
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif
	@${MKDIR} ${PREFIX}/lib/erlang/lib/xmlrpc-${PORTVERSION}
	@${MKDIR} ${PREFIX}/lib/erlang/lib/xmlrpc-${PORTVERSION}/ebin
	@${MKDIR} ${PREFIX}/lib/erlang/lib/xmlrpc-${PORTVERSION}/src
	@${INSTALL_DATA} ${WRKSRC}/ebin/* ${PREFIX}/lib/erlang/lib/xmlrpc-${PORTVERSION}/ebin
	@${INSTALL_DATA} ${WRKSRC}/src/* ${PREFIX}/lib/erlang/lib/xmlrpc-${PORTVERSION}/src
	@${INSTALL_MAN} ${WRKSRC}/doc/xmlrpc.3 ${MANPREFIX}/man/man3/erlang_xmlrpc.3

.include <bsd.port.mk>
