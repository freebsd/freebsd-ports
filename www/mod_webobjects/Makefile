# New ports collection makefile for:    mod_webobjects
# Date created:                         Mon Apr 16 07:07:22 EST 2007
# Whom:                                 Quinton Dolan <q@onthenet.com.au>
#
# $FreeBSD$
#

PORTNAME=	webobjects
PKGNAMEPREFIX=	mod_

MAINTAINER?=	q@onthenet.com.au
COMMENT=	WebObjects WebServer Adaptor for Apache

MASTERDIR=	${.CURDIR}/../woadaptor

WITH_APACHE?=	"yes"
WITHOUT_CGI=	"yes"
WITHOUT_FASTCGI="yes"

CONFLICTS=	woadaptor-[0-9]*

.include "${MASTERDIR}/Makefile"
