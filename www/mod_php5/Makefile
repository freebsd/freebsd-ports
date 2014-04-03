# Created by:	marcus@FreeBSD.org
# $FreeBSD$

PORTEPOCH=	1
CATEGORIES=	www devel
PKGNAMEPREFIX=	mod_

MAINTAINER=	ale@FreeBSD.org

PHP_PORT=	lang/php5
MASTERDIR=	${.CURDIR}/../../${PHP_PORT}

OPTIONS_DEFINE=	AP2FILTER
AP2FILTER_DESC=	Use Apache 2.x filter interface (experimental)
OPTIONS_EXCLUDE=	CGI CLI FPM EMBED

.include "${MASTERDIR}/Makefile"
