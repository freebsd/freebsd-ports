# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	train-core
PORTVERSION=	3.10.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Minimal Train with a backends for ssh and winrm

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-addressable>=2.5<3:www/rubygem-addressable \
		rubygem-ffi>=1.3.1:devel/rubygem-ffi \
		rubygem-json>=1.8<3.0:devel/rubygem-json \
		rubygem-mixlib-shellout>=2.0<4.0:devel/rubygem-mixlib-shellout \
		rubygem-net-scp>=1.2<4.0:security/rubygem-net-scp \
		rubygem-net-ssh>=2.9,2<7.0,2:security/rubygem-net-ssh

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
