# New ports collection makefile for:    ruby-wgettsv
# Date created:                         17 Jan 2009
# Whom:                                 Qing Feng <qingfeng@me.com>
#
# $FreeBSD$
#

PORTNAME=	ruby-wgettsv
PORTVERSION=	0.95
CATEGORIES=	www ruby
MASTER_SITES=	http://alpha.mixi.co.jp/dist/tctsearch/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	wgettsv
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	qingfeng@me.com
COMMENT=	Collect WWW resources and generate TSV data

USE_RUBY=		yes
USE_RUBY_FEATURES=	iconv

NO_BUILD=		yes

PLIST_FILES=	bin/wgettsv

post-extract:
	${CP} ${DISTDIR}/${DISTNAME} ${WRKDIR}/${DISTNAME}

do-configure:
	${SED} -e "s,^#!/usr/bin/ruby -w,#!${RUBY} -w," \
		    <${DISTDIR}/${DISTNAME} >${WRKDIR}/${DISTNAME}
do-install:
	${INSTALL_DATA} -m0755 ${WRKDIR}/${DISTNAME} ${PREFIX}/bin

do-package:
	#

.include <bsd.port.mk>
