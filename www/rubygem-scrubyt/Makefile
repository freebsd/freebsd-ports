# New ports collection makefile for:	rubygem-scrubyt
# Date created:		2007-03-13
# Whom:			TAKATSU Tomonari <tota@rtfm.jp>
#
# $FreeBSD$
#

PORTNAME=	scrubyt
PORTVERSION=	0.2.6
CATEGORIES=	www rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	tota@rtfm.jp
COMMENT=	A powerful web scraping toolkit written in Ruby

RUN_DEPENDS=	rubygem-mechanize>=0.6.3:${PORTSDIR}/www/rubygem-mechanize

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
