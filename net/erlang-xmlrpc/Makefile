# $FreeBSD$

PORTNAME=	xmlrpc
PORTVERSION=	1.13
PORTREVISION=	13
CATEGORIES=	net
MASTER_SITES=	http://www.erlang.org/contrib/
PKGNAMEPREFIX=	erlang-
DIST_SUBDIR=	erlang

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Library for XMLRPC support in Erlang

BROKEN=		unfetchable

USES=		gmake erlang tar:tgz
WRKSRC=		${WRKDIR}/xmlrpc-${PORTVERSION}

ERL_DOCS=	doc/xmlrpc.pdf doc/xmlrpc.ps doc/xmlrpc.txt

OPTIONS_DEFINE=	DOCS EXAMPLES

do-build:
	cd ${WRKSRC}/src && ${GMAKE}

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|XMERL_PATH=.*|XMERL_PATH=${LOCALBASE}/lib/erlang/lib/xmerl|g' ${WRKSRC}/src/Makefile
	@${RM} ${WRKSRC}/src/*.orig

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/xmlrpc.3 ${STAGEDIR}${MANPREFIX}/man/man3/erlang_xmlrpc.3

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
