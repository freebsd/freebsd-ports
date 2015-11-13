# Created by: Peter Schuller <peter.schuller@infidyne.com>
# $FreeBSD$

PORTNAME=	jekyll
PORTVERSION=	3.0.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Simple, blog aware, static site generator

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-colorator>=0.1:${PORTSDIR}/textproc/rubygem-colorator \
		rubygem-jekyll-sass-converter>=1.0:${PORTSDIR}/textproc/rubygem-jekyll-sass-converter \
		rubygem-jekyll-watch>=1.1:${PORTSDIR}/www/rubygem-jekyll-watch \
		rubygem-kramdown>=1.3:${PORTSDIR}/textproc/rubygem-kramdown \
		rubygem-liquid>=3.0.0:${PORTSDIR}/textproc/rubygem-liquid \
		rubygem-mercenary>=0.3.3:${PORTSDIR}/devel/rubygem-mercenary \
		rubygem-rouge>=1.7:${PORTSDIR}/textproc/rubygem-rouge \
		rubygem-safe_yaml>=1.0:${PORTSDIR}/devel/rubygem-safe_yaml

CONFLICTS_INSTALL=	rubygem-jekyll2-*
NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/jekyll

.include <bsd.port.mk>
