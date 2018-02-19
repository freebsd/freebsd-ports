# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	varnish-modules
DISTVERSION=	0.12.1
PORTREVISION=	0
CATEGORIES=	www

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Collection of Varnish Cache modules by Varnish Software

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	rst2man:textproc/py-docutils

USES=		autoreconf:build gmake libtool pkgconfig python:2.7,build varnish
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip

USE_GITHUB=	yes
GH_ACCOUNT=	varnish

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS
PORTDOCS=	*

pre-configure:
	cd ${WRKSRC} && ./bootstrap

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} '-not -regex .*.man.rst'

.include <bsd.port.mk>
