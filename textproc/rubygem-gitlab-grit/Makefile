PORTNAME=	gitlab-grit
PORTVERSION=	2.8.3
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Library for extracting information from a git repository

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-charlock_holmes>=0.7<1:textproc/rubygem-charlock_holmes \
		rubygem-diff-lcs>=1.1<2:textproc/rubygem-diff-lcs \
		rubygem-mime-types>=1.16:misc/rubygem-mime-types \
		rubygem-posix-spawn>=0.3<1:devel/rubygem-posix-spawn

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
