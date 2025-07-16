PORTNAME=	openvoxserver-ca
PORTVERSION=	3.0.0
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Ruby CLI tool to interact with the OpenVox Server Certificate Authority
WWW=		https://github.com/OpenVoxProject/openvoxserver-ca-cli/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-openfact>=5.0.0:sysutils/rubygem-openfact

USES=		gem

CONFLICTS_INSTALL=	rubygem-puppetserver-ca

NO_ARCH=	yes

PLIST_FILES=	bin/puppetserver-ca

.include <bsd.port.mk>
