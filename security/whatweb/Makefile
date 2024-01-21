PORTNAME=	whatweb
DISTVERSION=	0.5.5-${GH_TAGNAME}
PORTREVISION=	1
CATEGORIES=	security www

MAINTAINER=	jamie@catflap.org
COMMENT=	Tool to fingerprint web site components
WWW=		https://www.morningstarsecurity.com/research/whatweb

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_TUPLE=	urbanadventurer:WhatWeb:1b35169

RUN_DEPENDS=	rubygem-public_suffix>0:dns/rubygem-public_suffix \
		rubygem-ipaddr>0:net/rubygem-ipaddr \
		rubygem-addressable>0:www/rubygem-addressable

USES=		cpe ruby:run
CPE_VENDOR=	morningstarsecurity
NO_BUILD=	yes
NO_ARCH=	yes
PORTDOCS=	CHANGELOG.md INSTALL.md README.md whatweb.xsl

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e \
	's!/usr/share/whatweb/!${RUBY_SITELIBDIR}/whatweb!' \
	${WRKSRC}/whatweb

do-install:
.for dir in addons lib my-plugins plugin-development plugins plugins-disabled
	( cd ${WRKSRC}/${dir} && \
	${COPYTREE_SHARE} . ${STAGEDIR}${RUBY_SITELIBDIR}/whatweb/${dir} )
.endfor
	${INSTALL_MAN} ${WRKSRC}/whatweb.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_SCRIPT} ${WRKSRC}/whatweb ${STAGEDIR}${PREFIX}/bin/whatweb

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
