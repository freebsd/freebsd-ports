# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	gollum-lib
PORTVERSION=	4.2.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Simple, Git-powered wiki with a sweet API and local frontend

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-github-markup>=1.4.0:textproc/rubygem-github-markup \
		rubygem-gollum-grit_adapter>=1.0:www/rubygem-gollum-grit_adapter \
		rubygem-nokogiri>=1.6.4:textproc/rubygem-nokogiri \
		rubygem-rouge>=1.10:textproc/rubygem-rouge \
		rubygem-sanitize>=2.1.0:textproc/rubygem-sanitize \
		rubygem-stringex>=2.5.1:devel/rubygem-stringex

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
