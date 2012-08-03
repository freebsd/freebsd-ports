# New ports collection makefile for:	rubygem-earthquake
# Date created:		2012-05-21
# Whom:			Koichiro IWAO <meta+ports@vmeta.jp>
#
# $FreeBSD$
#

PORTNAME=	earthquake
PORTVERSION=	0.9.3
CATEGORIES=	net-im rubygems
MASTER_SITES=	RG

MAINTAINER=	meta+ports@vmeta.jp
COMMENT=	Terminal based Twitter client with Twitter streaming API

RUN_DEPENDS=	rubygem-twitter-stream>=0.1.15:${PORTSDIR}/net/rubygem-twitter-stream \
		rubygem-notify>=0.2.1:${PORTSDIR}/devel/rubygem-notify \
		rubygem-i18n>=0.6.0:${PORTSDIR}/devel/rubygem-i18n \
		rubygem-activesupport>=3.2.1:${PORTSDIR}/devel/rubygem-activesupport \
		rubygem-awesome_print>=1.0.2:${PORTSDIR}/devel/rubygem-awesome_print \
		rubygem-launchy>=2.0.5:${PORTSDIR}/devel/rubygem-launchy \
		rubygem-oauth>=0.4.5:${PORTSDIR}/net/rubygem-oauth \
		rubygem-twitter_oauth>=0.4.3:${PORTSDIR}/security/rubygem-twitter_oauth \
		rubygem-slop>=2.4.4:${PORTSDIR}/devel/rubygem-slop

USE_RUBY=	yes
USE_RUBYGEMS=	yes
USE_RAKE=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/earthquake

.include <bsd.port.mk>
