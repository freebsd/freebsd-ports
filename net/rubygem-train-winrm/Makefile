PORTNAME=	train-winrm
PORTVERSION=	0.3.1
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Allow applictaions using Train to speak to Windows using Remote Management
WWW=		https://github.com/inspec/train-winrm

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-chef-winrm>=2.4<3:sysutils/rubygem-chef-winrm \
		rubygem-chef-winrm-elevated>=1.2.5<1.3:sysutils/rubygem-chef-winrm-elevated \
		rubygem-chef-winrm-fs>=1.4.0<1.5:filesystems/rubygem-chef-winrm-fs \
		rubygem-syslog>=0.1<1:devel/rubygem-syslog

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
