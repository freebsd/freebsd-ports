PORTNAME=	puppetserver-ca
PORTVERSION=	2.7.1
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Ruby CLI tool to interact with the Puppet Server Certificate Authority
WWW=		https://github.com/puppetlabs/puppetserver-ca-cli/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Discontinued, use sysutils/rubygem-openvoxserver-ca
EXPIRATION_DATE=2026-07-01

RUN_DEPENDS=	rubygem-facter>=2.0.1:sysutils/rubygem-facter

USES=		gem

CONFLICTS_INSTALL=	rubygem-openvoxserver-ca

NO_ARCH=	yes

PLIST_FILES=	bin/puppetserver-ca

.include <bsd.port.mk>
