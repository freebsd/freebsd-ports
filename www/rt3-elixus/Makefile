# New ports collection makefile for:	rt3-elixus
# Date created:				5 May 2003
# Whom:					autrijus
#
# $FreeBSD$
#

PORTVERSION=	20041022
MASTER_SITES=	http://p4.elixus.org/hist/
PKGNAMESUFFIX=	-elixus

MAINTAINER=	autrijus@autrijus.org
COMMENT=	An industrial-grade ticketing system with elixus.org patches

BUILD_DEPENDS=	${SITE_PERL}/Data/ShowTable.pm:${PORTSDIR}/devel/p5-Data-ShowTable \
		${SITE_PERL}/Test/MockObject.pm:${PORTSDIR}/devel/p5-Test-MockObject \
		${SITE_PERL}/HTML/Scrubber.pm:${PORTSDIR}/www/p5-HTML-Scrubber \
		${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML

.if defined(WITH_APACHE2)
BUILD_DEPENDS+=	${SITE_PERL}/MasonX/Apache2Handler.pm:${PORTSDIR}/www/p5-MasonX-Apache2Handler
.endif

BROKEN=		Install fails

MASTERDIR=	${.CURDIR}/../../www/rt3
MD5_FILE=	${.CURDIR}/distinfo
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

do-patch:
	${TRUE}

.include "${MASTERDIR}/Makefile"
