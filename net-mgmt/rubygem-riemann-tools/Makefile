PORTNAME=	riemann-tools
DISTVERSION=	1.12.0
CATEGORIES=	net-mgmt rubygems
MASTER_SITES=	RG

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Collection of utilities which submit events to Riemann
WWW=		https://github.com/riemann/riemann-tools

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-csv>=3.0:devel/rubygem-csv \
		rubygem-json>=1.8:devel/rubygem-json \
		rubygem-optimist>=3.0:devel/rubygem-optimist \
		rubygem-riemann-client>=1.1:net-mgmt/rubygem-riemann-client

USES=		gem

NO_ARCH=	yes

post-patch:
		# hide sensitive command-line parameters from casual users
		@${SED} -i -e $$'/^#!.*ruby.*/a\\\nProcess.setproctitle($$0)\n' \
		    ${WRKSRC}/bin/riemann-*

PORTDOCS=	README.markdown

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
