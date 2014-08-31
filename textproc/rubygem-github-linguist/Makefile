# $FreeBSD$

PORTNAME=	github-linguist
PORTVERSION=	3.1.2
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	GitHub Language detection

LICENSE=	MIT

RUN_DEPENDS=	rubygem-charlock_holmes>=0.7.3:${PORTSDIR}/textproc/rubygem-charlock_holmes \
		rubygem-escape_utils>=1.0.1:${PORTSDIR}/textproc/rubygem-escape_utils \
		rubygem-mime-types>=1.19:${PORTSDIR}/misc/rubygem-mime-types \
		rubygem-pygments.rb>=0.6.0:${PORTSDIR}/devel/rubygem-pygments.rb \
		rubygem-rugged>=0:${PORTSDIR}/devel/rubygem-rugged

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/linguist

.include <bsd.port.mk>
