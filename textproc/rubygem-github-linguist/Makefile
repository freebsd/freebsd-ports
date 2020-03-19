# $FreeBSD$

PORTNAME=	github-linguist
PORTVERSION=	7.6.1
PORTREVISION=	1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	GitHub Language detection

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-charlock_holmes>=0.7.6<0.8:textproc/rubygem-charlock_holmes \
		rubygem-escape_utils>=1.2.0<1.3:textproc/rubygem-escape_utils \
		rubygem-mini_mime>=1.0<2.0:mail/rubygem-mini_mime \
		rubygem-rugged>=0.25.1:devel/rubygem-rugged

# bin/linguist
#CONFLICTS_INSTALL=	qtchooser rubygem-github-linguist47 rubygem-gitlab-linguist

USES=		gem
USE_RUBY=	yes

PLIST_FILES=	bin/git-linguist bin/github-linguist

.include <bsd.port.mk>
