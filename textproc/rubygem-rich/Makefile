# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rich
PORTVERSION=	1.4.6
PORTREVISION=	1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Opinionated WYSIWYG editor for Rails based on CKEditor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-jquery-rails4>=4.0:www/rubygem-jquery-rails4 \
		rubygem-kaminari>=0:www/rubygem-kaminari \
		rubygem-mime-types>=0:misc/rubygem-mime-types \
		rubygem-paperclip>=0:devel/rubygem-paperclip \
		rubygem-rack-raw-upload>=0:devel/rubygem-rack-raw-upload \
		rubygem-rails4>=4.0:www/rubygem-rails4 \
		rubygem-sass-rails4>=4.0:textproc/rubygem-sass-rails4

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
