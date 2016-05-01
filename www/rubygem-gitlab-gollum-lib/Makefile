# $FreeBSD$

PORTNAME=	gitlab-gollum-lib
PORTVERSION=	1.1.0
PORTREVISION=	3
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Simple, Git-powered wiki with a sweet API and local frontend

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-github-markdown>=0.5.3:textproc/rubygem-github-markdown \
		rubygem-github-markup>=0.7.5:textproc/rubygem-github-markup \
		rubygem-gitlab-grit>=2.6.1:textproc/rubygem-gitlab-grit \
		rubygem-nokogiri>=1.5.9:textproc/rubygem-nokogiri \
		rubygem-sanitize>=2.0.3:textproc/rubygem-sanitize \
		rubygem-stringex>=1.5.1:devel/rubygem-stringex

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
