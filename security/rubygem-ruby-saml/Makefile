PORTNAME=	ruby-saml
PORTVERSION=	1.18.1
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	SAML toolkit for Ruby on Rails
WWW=		https://developers.onelogin.com/saml/ruby \
		https://github.com/SAML-Toolkits/ruby-saml

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-nokogiri>=1.13.10:textproc/rubygem-nokogiri \
		rubygem-rexml>=0:textproc/rubygem-rexml

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
