# $FreeBSD$

PORTNAME=	gitlab-grit
PORTVERSION=	2.6.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Library for extracting information from a git repository in an object oriented manner

RUN_DEPENDS=	rubygem-charlock_holmes>=0.6.9:${PORTSDIR}/textproc/rubygem-charlock_holmes \
		rubygem-diff-lcs>=1.1:${PORTSDIR}/textproc/rubygem-diff-lcs \
		rubygem-mime-types>=1.15:${PORTSDIR}/misc/rubygem-mime-types \
		rubygem-posix-spawn>=0.3.6:${PORTSDIR}/devel/rubygem-posix-spawn

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes


.include <bsd.port.mk>
