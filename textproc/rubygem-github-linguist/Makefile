# $FreeBSD$

PORTNAME=	github-linguist
PORTVERSION=	4.5.15
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	GitHub Language detection

LICENSE=	MIT

RUN_DEPENDS=	rubygem-charlock_holmes>=0.7.3:${PORTSDIR}/textproc/rubygem-charlock_holmes \
		rubygem-escape_utils>=1.1.0:${PORTSDIR}/textproc/rubygem-escape_utils \
		rubygem-mime-types>=1.19:${PORTSDIR}/misc/rubygem-mime-types \
		rubygem-rugged>=0.23.0b:${PORTSDIR}/devel/rubygem-rugged

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/linguist

.include <bsd.port.mk>
