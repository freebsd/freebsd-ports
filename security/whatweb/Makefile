# Created by: Niels Heinen
# $FreeBSD$

PORTNAME=	whatweb
DISTVERSION=	0.4.8-${GH_TAGNAME}
PORTREVISION=	2
CATEGORIES=	security www

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Tool to fingerprint web site components

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_TUPLE=	urbanadventurer:WhatWeb:f467aa2

USE_RUBY=		yes
RUBY_NO_BUILD_DEPENDS=	yes
NO_BUILD=		yes
NO_ARCH=		yes
PORTDOCS=		CHANGELOG INSTALL README whatweb.xsl

post-patch:
	${REINPLACE_CMD} -e \
	's!/usr/share/whatweb/!${RUBY_SITELIBDIR}/whatweb!' \
	${WRKSRC}/whatweb

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.for dir in addons lib my-plugins plugin-development plugins plugins-disabled
	( cd ${WRKSRC}/${dir} && \
	${COPYTREE_SHARE} . ${STAGEDIR}${RUBY_SITELIBDIR}/whatweb/${dir} )
.endfor
	${INSTALL_MAN} ${WRKSRC}/whatweb.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_SCRIPT} ${WRKSRC}/whatweb ${STAGEDIR}${PREFIX}/bin/whatweb

.include <bsd.port.mk>
