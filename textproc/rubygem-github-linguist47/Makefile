# $FreeBSD$

PORTNAME=	github-linguist
PORTVERSION=	4.7.6
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	47

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	GitHub Language detection

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Obsoleted by update of www/gitlab. Please use textproc/rubygem-github-linguist instead
EXPIRATION_DATE=	2018-05-31

RUN_DEPENDS=	rubygem-charlock_holmes>=0.7.3:textproc/rubygem-charlock_holmes \
		rubygem-escape_utils11>=1.1.0:textproc/rubygem-escape_utils11 \
		rubygem-mime-types>=1.19:misc/rubygem-mime-types \
		rubygem-rugged>=0.23.0b:devel/rubygem-rugged

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes
# bin/linguist
CONFLICTS_INSTALL=	qtchooser rubygem-github-linguist rubygem-gitlab-linguist
PLIST_FILES=	bin/git-linguist bin/linguist

PORTSCOUT=	limit:^4\.7\.

.include <bsd.port.mk>
