# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	gitlab-flowdock-git-hook
PORTVERSION=	1.0.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	GitLab-patched Git Post-Receive hook for Flowdock

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-flowdock>=0.7:www/rubygem-flowdock \
		rubygem-gitlab-grit>=2.4.1:textproc/rubygem-gitlab-grit \
		rubygem-multi_json>=0:devel/rubygem-multi_json

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
