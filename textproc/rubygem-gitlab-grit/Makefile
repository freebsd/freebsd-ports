# $FreeBSD$

PORTNAME=	gitlab-grit
PORTVERSION=	2.7.3
PORTREVISION=	1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Library for extracting information from a git repository

LICENSE=	MIT

RUN_DEPENDS=	rubygem-charlock_holmes>=0.6:${PORTSDIR}/textproc/rubygem-charlock_holmes \
		rubygem-diff-lcs>=1.1:${PORTSDIR}/textproc/rubygem-diff-lcs \
		rubygem-mime-types1>=1.15:${PORTSDIR}/misc/rubygem-mime-types1 \
		rubygem-posix-spawn>=0.3:${PORTSDIR}/devel/rubygem-posix-spawn

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
