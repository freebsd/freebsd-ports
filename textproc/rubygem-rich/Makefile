# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rich
PORTVERSION=	1.4.6
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	An opinionated WYSIWYG editor for Rails based on CKEditor

RUN_DEPENDS=	rubygem-jquery-rails>=0:${PORTSDIR}/www/rubygem-jquery-rails \
		rubygem-kaminari>=0:${PORTSDIR}/www/rubygem-kaminari \
		rubygem-mime-types>=0:${PORTSDIR}/misc/rubygem-mime-types \
		rubygem-paperclip>=0:${PORTSDIR}/devel/rubygem-paperclip \
		rubygem-rack-raw-upload>=0:${PORTSDIR}/devel/rubygem-rack-raw-upload \
		rubygem-rails>=3.2.0:${PORTSDIR}/www/rubygem-rails \
		rubygem-sass-rails>=0:${PORTSDIR}/textproc/rubygem-sass-rails

USE_RUBY=	yes
USE_RUBYGEMS=	yes
USE_RAKE=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
