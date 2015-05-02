# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	gollum-lib
PORTVERSION=	3.0.0
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Simple, Git-powered wiki with a sweet API and local frontend

LICENSE=	MIT

RUN_DEPENDS=	rubygem-github-markup>=1.1.0:${PORTSDIR}/textproc/rubygem-github-markup \
		rubygem-gitlab-grit>=2.6.5:${PORTSDIR}/textproc/rubygem-gitlab-grit \
		rubygem-nokogiri>=1.6.1:${PORTSDIR}/textproc/rubygem-nokogiri \
		rubygem-rouge>=1.3.3:${PORTSDIR}/textproc/rubygem-rouge \
		rubygem-sanitize>=2.1.0:${PORTSDIR}/textproc/rubygem-sanitize \
		rubygem-stringex>=2.5.1:${PORTSDIR}/devel/rubygem-stringex

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
