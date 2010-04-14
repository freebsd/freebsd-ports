# New ports collection makefile for:    whatweb
# Date created:				2010-04-11
# Whom:					Niels Heinen
#
# $FreeBSD$
#

PORTNAME=	whatweb
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	security www
MASTER_SITES=	http://www.morningstarsecurity.com/downloads/

MAINTAINER=	niels@FreeBSD.org
COMMENT=	A tool to fingerprint web site components

RUN_DEPENDS=	rubygem-anemone>=0.4.0:${PORTSDIR}/www/rubygem-anemone

USE_RUBY=	yes
NO_BUILD=	yes
PORTDOCS=	README INSTALL CHANGELOG TODO

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e \
	's!PLUGIN_DIR="!PLUGIN_DIR="${RUBY_SITELIBDIR}/${PORTNAME}/!' \
	${WRKSRC}/${PORTNAME}

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.	for i in ${PORTDOCS}
		${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.	endfor
.endif
.for DIR in plugins lib plugin-development
	( cd ${WRKSRC}/${DIR} && \
	${COPYTREE_SHARE} . ${RUBY_SITELIBDIR}/${PORTNAME}/${DIR} )
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.post.mk>
