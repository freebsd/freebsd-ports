PORTNAME=	chef-winrm
PORTVERSION=	2.4.4
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby library for Windows Remote Management
WWW=		https://github.com/chef/chef-winrm

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-builder>=2.1.2:devel/rubygem-builder \
		rubygem-chef-gyoku>=1.5<2:textproc/rubygem-chef-gyoku \
		rubygem-erubi>=1.8:www/rubygem-erubi \
		rubygem-gssapi>=1.2<2:security/rubygem-gssapi \
		rubygem-httpclient>=2.2.0.2<3:www/rubygem-httpclient \
		rubygem-logging>=1.6.1<3.0:devel/rubygem-logging \
		rubygem-nori>=2.7.0:devel/rubygem-nori \
		rubygem-rexml>=3.3<4:textproc/rubygem-rexml \
		rubygem-rubyntlm>=0.6.3<0.7:net/rubygem-rubyntlm

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/rwinrm

.include <bsd.port.mk>
