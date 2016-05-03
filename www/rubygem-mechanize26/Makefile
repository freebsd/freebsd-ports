# $FreeBSD$

PORTNAME=	mechanize
PORTVERSION=	2.6.0
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	26

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	WWW::Mechanize, a handy web browsing ruby object

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.rdoc

RUN_DEPENDS=	rubygem-domain_name>=0.5.1:net/rubygem-domain_name \
		rubygem-http-cookie>=1.0.0:www/rubygem-http-cookie \
		rubygem-mime-types1>=0:misc/rubygem-mime-types1 \
		rubygem-net-http-digest_auth11>=0:www/rubygem-net-http-digest_auth11 \
		rubygem-net-http-persistent25>0:www/rubygem-net-http-persistent25 \
		rubygem-nokogiri14>=1.4:textproc/rubygem-nokogiri14 \
		rubygem-ntlm-http>=0.1.1:www/rubygem-ntlm-http \
		rubygem-webrobots>=0.0.9:www/rubygem-webrobots

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PORTSCOUT=	limit:^2\.6

.include <bsd.port.mk>
