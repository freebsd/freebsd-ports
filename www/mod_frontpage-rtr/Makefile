# New ports collection makefile for:    Microsoft FrontPage Extensions
# Date created:         Tue Feb  4 13:59:20 CST 2003
# Whom:                 hetzels@westbend.net
#
# $FreeBSD$
#

CATEGORIES=	www

MAINTAINER=	hetzels@westbend.net

WANT_APACHE=	13

PKGMESSAGE=	${MASTERDIR}/pkg-message13

.if defined(WITH_SSL)
AP_PORT=	www/apache13-modssl
.endif

MASTERDIR=	${.CURDIR}/../mod_frontpage2-rtr

.include "${MASTERDIR}/Makefile"
