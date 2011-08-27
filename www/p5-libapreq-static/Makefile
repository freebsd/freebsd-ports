# New ports collection makefile for:	p5-libapreq-static
# Date created:			6 Jun 2003
# Whom:				Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$

PKGNAMESUFFIX=	-static

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/apache13-modperl

MASTERDIR=	${.CURDIR}/../p5-libapreq

DEPRECATED=	apache13 is deprecated, migrate to 2.2.x+ now
EXPIRATION_DATE=	one week after FreeBSD 9.0-RELEASE-p0

.include "${MASTERDIR}/Makefile"
