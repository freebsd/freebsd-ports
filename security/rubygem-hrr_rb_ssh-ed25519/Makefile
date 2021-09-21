PORTNAME=	hrr_rb_ssh-ed25519
DISTVERSION=	0.4.2
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	hrr_rb_ssh extension that supports ED25519

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-ed25519>=1.2:security/rubygem-ed25519 \
		rubygem-hrr_rb_ssh>=0.4:security/rubygem-hrr_rb_ssh

NO_ARCH=	yes
USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>
