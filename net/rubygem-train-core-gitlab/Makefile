PORTNAME=	train-core
PORTVERSION=	3.16.5
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Minimal Train with a backends for ssh and winrm
WWW=		https://github.com/inspec/train

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-addressable>=2.5<3:www/rubygem-addressable \
		rubygem-ffi>=1.16.0<1.18:devel/rubygem-ffi \
		rubygem-json2>=2.19.2<3.0:devel/rubygem-json2 \
		rubygem-mixlib-shellout>=2.0<4.0:devel/rubygem-mixlib-shellout \
		rubygem-net-scp-gitlab>=1.2<5.0:security/rubygem-net-scp-gitlab \
		rubygem-net-ssh-gitlab>=2.9<8.0:security/rubygem-net-ssh-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
