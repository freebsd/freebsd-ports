# $FreeBSD$

PORTNAME=	github-linguist
PORTVERSION=	5.0.11
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	GitHub Language detection

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-charlock_holmes>=0.7.3:textproc/rubygem-charlock_holmes \
		rubygem-escape_utils>=1.1.0:textproc/rubygem-escape_utils \
		rubygem-mime-types>=1.19:misc/rubygem-mime-types \
		rubygem-rugged>=0.25.1:devel/rubygem-rugged

# bin/linguist
CONFLICTS_INSTALL=	rubygem-gitlab-linguist

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/git-linguist bin/linguist

.include <bsd.port.mk>
