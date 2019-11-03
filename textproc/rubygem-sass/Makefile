# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sass
PORTVERSION=	3.7.4
CATEGORIES=	textproc ruby
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Sass is an extension of CSS3

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-sass-listen>=4.0.0<4.1:textproc/rubygem-sass-listen

USES=		gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/sass bin/sass-convert bin/scss

# bin/sass bin/sass-convert bin/scss
CONFLICTS_INSTALL=	rubygem-sass34

SHEBANG_FILES=	extra/sass-spec-ref.sh

.include <bsd.port.mk>
