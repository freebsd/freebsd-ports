PORTNAME=	github-linguist
PORTVERSION=	7.28.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	GitHub Language detection
WWW=		https://github.com/github-linguist/linguist

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-cgi>=0:www/rubygem-cgi \
		rubygem-charlock_holmes>=0.7.7<0.8:textproc/rubygem-charlock_holmes \
		rubygem-mini_mime>=1.0<2:mail/rubygem-mini_mime \
		rubygem-rugged>=1.0<2:devel/rubygem-rugged

USES=		gem

PLIST_FILES=	bin/git-linguist bin/github-linguist

.include <bsd.port.mk>
