# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	gitlab-flowdock-git-hook
PORTVERSION=	0.4.2.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	GitLab's patched Git Post-Receive hook for Flowdock

LICENSE=	MIT

RUN_DEPENDS=	rubygem-gitlab-grit>=2.4.1:${PORTSDIR}/textproc/rubygem-gitlab-grit \
		rubygem-multi_json>=0:${PORTSDIR}/devel/rubygem-multi_json

NO_ARCH=	yes
USE_RUBY=	yes
USE_RAKE=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
