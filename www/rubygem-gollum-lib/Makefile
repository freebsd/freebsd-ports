# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	gollum-lib
PORTVERSION=	4.2.2
PORTREVISION=	2
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Simple, Git-powered wiki with a sweet API and local frontend

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-gemojione>=2.2:graphics/rubygem-gemojione \
		rubygem-github-markup>=1.4:textproc/rubygem-github-markup \
		rubygem-gollum-grit_adapter>=1.0:www/rubygem-gollum-grit_adapter \
		rubygem-nokogiri>=1.6.4:textproc/rubygem-nokogiri \
		rubygem-rouge>=2.0:textproc/rubygem-rouge \
		rubygem-sanitize>=2.1:textproc/rubygem-sanitize \
		rubygem-stringex>=2.6:devel/rubygem-stringex

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
