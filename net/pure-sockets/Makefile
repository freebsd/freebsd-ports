# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	pure-sockets
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://cdn.bitbucket.org/purelang/pure-lang/downloads/
DIST_SUBDIR=	pure

MAINTAINER=	lichray@gmail.com
COMMENT=	Pure language interface to the Berkeley socket functions

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	dual

USES=		pure

PLIST_FILES=	lib/pure/sockets.pure \
		lib/pure/sockets.so

NO_STAGE=	yes

PORTDOCS=	README

PORTEXAMPLES=	*

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
