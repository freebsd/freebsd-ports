PORTNAME=	train-core
PORTVERSION=	3.13.4
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Minimal Train with a backends for ssh and winrm
WWW=		https://github.com/inspec/train

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-addressable>=2.5<3:www/rubygem-addressable \
		rubygem-ffi>=1.16.0:devel/rubygem-ffi \
		rubygem-json>=1.8<3.0:devel/rubygem-json \
		rubygem-mixlib-shellout>=2.0<4.0:devel/rubygem-mixlib-shellout \
		rubygem-net-scp>=1.2<5.0:security/rubygem-net-scp \
		rubygem-net-ssh6>=2.9<8.0:security/rubygem-net-ssh6

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
