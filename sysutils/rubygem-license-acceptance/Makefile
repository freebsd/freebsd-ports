# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	license-acceptance
PORTVERSION=	1.0.19
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Chef End User License Agreement Acceptance for Ruby products

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-pastel>=0.7<1:devel/rubygem-pastel \
		rubygem-tomlrb>=1.2<2:textproc/rubygem-tomlrb \
		rubygem-tty-box>=0.3<1:devel/rubygem-tty-box \
		rubygem-tty-prompt>=0.18<1:devel/rubygem-tty-prompt

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
