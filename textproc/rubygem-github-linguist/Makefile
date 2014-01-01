# $FreeBSD$

PORTNAME=	github-linguist
PORTVERSION=	2.10.9
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	GitHub Language detection

LICENSE=	MIT

RUN_DEPENDS=	rubygem-charlock_holmes>=0.6.6:${PORTSDIR}/textproc/rubygem-charlock_holmes \
		rubygem-escape_utils>=0.3.1:${PORTSDIR}/textproc/rubygem-escape_utils \
		rubygem-mime-types>=1.19:${PORTSDIR}/misc/rubygem-mime-types \
		rubygem-pygments.rb>=0.5.4:${PORTSDIR}/devel/rubygem-pygments.rb

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/linguist

.include <bsd.port.mk>
