# $FreeBSD$

PORTNAME=	gitlab-grit
PORTVERSION=	2.8.1
PORTREVISION=	1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Library for extracting information from a git repository

LICENSE=	MIT

RUN_DEPENDS=	rubygem-charlock_holmes>=0.6:textproc/rubygem-charlock_holmes \
		rubygem-diff-lcs>=1.1:textproc/rubygem-diff-lcs \
		rubygem-mime-types>=1.16:misc/rubygem-mime-types \
		rubygem-posix-spawn>=0.3:devel/rubygem-posix-spawn

NO_ARCH=	yes

USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
