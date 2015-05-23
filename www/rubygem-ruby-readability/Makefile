# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ruby-readability
PORTVERSION=	0.7.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Readability for Ruby

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-guess_html_encoding>=0.0.4:${PORTSDIR}/devel/rubygem-guess_html_encoding \
		rubygem-nokogiri>=1.6.0:${PORTSDIR}/textproc/rubygem-nokogiri

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/readability

.include <bsd.port.mk>
