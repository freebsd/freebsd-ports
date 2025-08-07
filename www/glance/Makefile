PORTNAME=	glance
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.8
PORTREVISION=	5
CATEGORIES=	www

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Self-hosted dashboard that puts all your feeds in one place
WWW=		https://github.com/glanceapp/glance

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/glanceapp/glance

OPTIONS_DEFINE=	DOCS EXAMPLES

PLIST_FILES=	bin/glance
PORTDOCS=	configuration.md \
		custom-api.md \
		extensions.md \
		preconfigured-pages.md \
		themes.md \
		v0.7.0-upgrade.md
PORTEXAMPLES=	glance.yml

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.md ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/glance.yml ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
