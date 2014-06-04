# Created by: Niels Heinen
# $FreeBSD$

PORTNAME=	whatweb
DISTVERSION=	0.4.8-${GH_COMMIT}
CATEGORIES=	security www

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Tool to fingerprint web site components

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	urbanadventurer
GH_PROJECT=	WhatWeb
GH_COMMIT=	126e729
GH_TAGNAME=	${GH_COMMIT}

USE_RUBY=		yes
USE_RUBY_FEATURES=	iconv
RUBY_NO_BUILD_DEPENDS=	yes
NO_BUILD=		yes
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
