# New ports collection makefile for:	erlang_xmlrpc
# Date Created:				5 March 2003
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	erlang_xmlrpc
PORTVERSION=	1.13
PORTREVISION=	8
CATEGORIES=	net
MASTER_SITES=	http://www.erlang.org/contrib/
DISTNAME=	xmlrpc-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	erlang

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A library for XMLRPC support in Erlang

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/xmlrpc-${PORTVERSION}

MAN3=		erlang_xmlrpc.3

XMLRPC_DOCS=	xmlrpc.pdf xmlrpc.ps xmlrpc.txt

post-patch:
	@${REINPLACE_CMD} -e 's|XMERL_PATH=.*|XMERL_PATH=${LOCALBASE}/lib/erlang/lib/xmerl|g' ${WRKSRC}/src/Makefile
	@${RM} ${WRKSRC}/src/Makefile.bak ${WRKSRC}/src/*.orig

do-build:
	@cd ${WRKSRC}/src && ${GMAKE}

do-install:
	@${MKDIR} ${DOCSDIR}
	@for FILE in ${XMLRPC_DOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/doc/$${FILE} ${DOCSDIR}; \
	done
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
	@${MKDIR} ${PREFIX}/lib/erlang/lib/xmlrpc
	@${CP} -r ${WRKSRC}/ebin ${PREFIX}/lib/erlang/lib/xmlrpc
	@${CP} -r ${WRKSRC}/src ${PREFIX}/lib/erlang/lib/xmlrpc
	@${INSTALL_MAN} ${WRKSRC}/doc/xmlrpc.3 ${MANPREFIX}/man/man3/erlang_xmlrpc.3
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/erlang/lib/xmlrpc

.include <bsd.port.mk>
