# $FreeBSD$

PORTNAME=	gitlab-gollum-lib
PORTVERSION=	1.0.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Simple, Git-powered wiki with a sweet API and local frontend.

RUN_DEPENDS=	rubygem-github-markdown>=0.5.3:${PORTSDIR}/textproc/rubygem-github-markdown \
		rubygem-github-markup>=0.7.5:${PORTSDIR}/textproc/rubygem-github-markup \
		rubygem-gitlab-grit>=2.5.1:${PORTSDIR}/textproc/rubygem-gitlab-grit \
		rubygem-nokogiri>=1.6.0:${PORTSDIR}/textproc/rubygem-nokogiri \
		rubygem-pygments.rb>=0.5.2:${PORTSDIR}/devel/rubygem-pygments.rb \
		rubygem-sanitize>=2.0.3:${PORTSDIR}/textproc/rubygem-sanitize \
		rubygem-stringex>=1.5.1:${PORTSDIR}/devel/rubygem-stringex

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes


.include <bsd.port.mk>
