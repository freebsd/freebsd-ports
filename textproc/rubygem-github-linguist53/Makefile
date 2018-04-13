# $FreeBSD$

PORTNAME=	github-linguist
PORTVERSION=	5.3.3
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	53

MAINTAINER=	idefix@fechner.net
COMMENT=	GitHub Language detection

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-charlock_holmes>=0.7.5:textproc/rubygem-charlock_holmes \
		rubygem-escape_utils>=1.1.0:textproc/rubygem-escape_utils \
		rubygem-mime-types>=1.19:misc/rubygem-mime-types \
		rubygem-rugged>=0.25.1:devel/rubygem-rugged

# bin/linguist
CONFLICTS_INSTALL=	qtchooser rubygem-gitlab-linguist

USES=		gem
USE_RUBY=	yes

PLIST_FILES=	bin/git-linguist bin/linguist

PORTSCOUT=	limit:^5\.3\.

.include <bsd.port.mk>
