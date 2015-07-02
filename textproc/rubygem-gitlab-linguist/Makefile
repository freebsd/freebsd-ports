# $FreeBSD$

PORTNAME=	gitlab-linguist
PORTVERSION=	3.0.1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	GitHub Language detection

LICENSE=	MIT

RUN_DEPENDS=	rubygem-charlock_holmes>=0.6.6:${PORTSDIR}/textproc/rubygem-charlock_holmes \
		rubygem-escape_utils-rails4>=0.3.1:${PORTSDIR}/textproc/rubygem-escape_utils-rails4 \
		rubygem-mime-types1>=1.19:${PORTSDIR}/misc/rubygem-mime-types1

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/linguist

.include <bsd.port.mk>
