PORTNAME=	license-acceptance
PORTVERSION=	2.1.13
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Chef End User License Agreement Acceptance for Ruby products

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-pastel>=0.7<1:devel/rubygem-pastel \
		rubygem-tomlrb1>=1.2<3.0:textproc/rubygem-tomlrb1 \
		rubygem-tty-box>=0.6<1:devel/rubygem-tty-box \
		rubygem-tty-prompt>=0.20<1:devel/rubygem-tty-prompt

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
