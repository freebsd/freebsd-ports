# Created by: Matthias Fechner <mfechner@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gitlab-puma_worker_killer
DISTVERSION=	0.1.1.gitlab.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Automatically restart Puma cluster workers based on max RAM available

LICENSE=	MIT

RUN_DEPENDS=	rubygem-get_process_mem>=0.2:devel/rubygem-get_process_mem \
		rubygem-gitlab-puma>=4.3.1.g.2<5:www/rubygem-gitlab-puma

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
