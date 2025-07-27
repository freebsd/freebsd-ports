PORTNAME=	winrm
DISTVERSION=	2.3.9
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for Windows Remote Management
WWW=		https://github.com/WinRb/WinRM

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-builder>=2.1.2:devel/rubygem-builder \
		rubygem-erubi>=1.8<2:www/rubygem-erubi \
		rubygem-gssapi>=1.2<2:security/rubygem-gssapi \
		rubygem-gyoku>=1.0<2:devel/rubygem-gyoku \
		rubygem-httpclient>=2.2.0.2<3:www/rubygem-httpclient \
		rubygem-logging>=1.6.1<3.0:devel/rubygem-logging \
		rubygem-nori>=2.7.1<3:devel/rubygem-nori \
		rubygem-rexml>=3.0<4:textproc/rubygem-rexml \
		rubygem-rubyntlm>=0.6.3<0.7:net/rubygem-rubyntlm

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/rwinrm

.include <bsd.port.mk>
