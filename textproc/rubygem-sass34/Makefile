# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sass
PORTVERSION=	3.4.25
CATEGORIES=	textproc ruby
MASTER_SITES=	RG
PKGNAMESUFFIX=	34

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Extension of CSS3

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

# bin/sass bin/sass-convert bin/scss
CONFLICTS_INSTALL=	rubygem-sass

PORTSCOUT=	limit:^3\.4\.

NO_ARCH=	yes
USES=		gem shebangfix
USE_RUBY=	yes
SHEBANG_FILES=	extra/sass-spec-ref.sh

PLIST_FILES=	bin/sass bin/sass-convert bin/scss

.include <bsd.port.mk>
