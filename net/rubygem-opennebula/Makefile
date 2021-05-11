# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	opennebula
PORTVERSION=	6.0.1
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Libraries needed to talk to OpenNebula

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-ipaddress>=0:net/rubygem-ipaddress \
		rubygem-json>=0:devel/rubygem-json \
		rubygem-nokogiri>=0:textproc/rubygem-nokogiri \
		rubygem-parse-cron>=0:textproc/rubygem-parse-cron \
		rubygem-rbvmomi>=0:net/rubygem-rbvmomi \
		rubygem-treetop>=0:devel/rubygem-treetop \
		rubygem-xmlrpc>=0:net/rubygem-xmlrpc

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
