PORTNAME=	ruby-saml
PORTVERSION=	1.15.0
CATEGORIES=	security rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	115

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	SAML toolkit for Ruby on Rails
WWW=		https://developers.onelogin.com/saml/ruby \
		https://github.com/SAML-Toolkits/ruby-saml

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-nokogiri>=1.13.10:textproc/rubygem-nokogiri \
		rubygem-rexml>=0:textproc/rubygem-rexml

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^1\.15\.

.include <bsd.port.mk>
