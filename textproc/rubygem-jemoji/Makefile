# $FreeBSD$

PORTNAME=	jemoji
PORTVERSION=	0.5.1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	GitHub-flavored emoji plugin for Jekyll

LICENSE=	MIT

RUN_DEPENDS=	rubygem-gemoji>=2.0:${PORTSDIR}/textproc/rubygem-gemoji \
		rubygem-html-pipeline>=2.2:${PORTSDIR}/textproc/rubygem-html-pipeline \
		rubygem-jekyll>=2.0:${PORTSDIR}/www/rubygem-jekyll

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
