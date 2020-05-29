# $FreeBSD$

PORTNAME=	riemann-rabbitmq
DISTVERSION=	0.1.3
PORTREVISION=	1
CATEGORIES=	net-mgmt rubygems
MASTER_SITES=	RG

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Send your RabbitMQ metrics to Riemann

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-riemann-tools>=0.2.14:net-mgmt/rubygem-riemann-tools \
		rubygem-faraday0>=0.8.5:www/rubygem-faraday0

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

post-patch:
		# hide sensitive command-line parameters from casual users
		@${SED} -i -e $$'/^#!.*ruby.*/a\\\nProcess.setproctitle($$0)\n' \
		    ${WRKSRC}/bin/riemann-*

PORTDOCS=	README.md

PLIST_FILES=	bin/riemann-rabbitmq

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
