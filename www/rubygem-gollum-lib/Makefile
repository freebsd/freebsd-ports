# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	gollum-lib
PORTVERSION=	4.2.2
PORTREVISION=	3
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Simple, Git-powered wiki with a sweet API and local frontend

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-gemojione>=2.2:graphics/rubygem-gemojione \
		rubygem-gollum-grit_adapter>=1.0:www/rubygem-gollum-grit_adapter \
		rubygem-nokogiri>=1.6.4:textproc/rubygem-nokogiri \
		rubygem-rouge>=2.0:textproc/rubygem-rouge \
		rubygem-sanitize>=2.1:textproc/rubygem-sanitize \
		rubygem-stringex>=2.6:devel/rubygem-stringex

OPTIONS_RADIO=	MARKUP
OPTIONS_RADIO_MARKUP=	GITHUB GITLAB
OPTIONS_DEFAULT?=	GITHUB

MARKUP_DESC=	Markup Selection
GITHUB_DESC=	Use rubygem-github-markup (default)
GITLAB_DESC=	Use rubygem-gitlab-markup instead

GITHUB_RUN_DEPENDS=	rubygem-github-markup>=1.4:textproc/rubygem-github-markup
GITLAB_RUN_DEPENDS=	rubygem-gitlab-markup>=1.5:textproc/rubygem-gitlab-markup

GITHUB_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-github-gemspec
GITLAB_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-gitlab-gemspec

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
