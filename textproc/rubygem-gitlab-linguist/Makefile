# $FreeBSD$

PORTNAME=	gitlab-linguist
PORTVERSION=	3.0.1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	GitHub Language detection

LICENSE=	MIT

RUN_DEPENDS=	rubygem-charlock_holmes>=0.6.6:textproc/rubygem-charlock_holmes \
		rubygem-escape_utils-rails4>=0.2.4:textproc/rubygem-escape_utils-rails4 \
		rubygem-mime-types1>=1.19:misc/rubygem-mime-types1

# bin/linguist
CONFLICTS_INSTALL=	qtchooser rubygem-github-linguist rubygem-github-linguist47

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/linguist

.include <bsd.port.mk>
