# New ports collection makefile for:	ipa
# Date created:				2 December 2000
# Whom:					Andrey Simonenko
#
# $FreeBSD$
#

PORTNAME=	ipa
PORTVERSION=	1.2.7
CATEGORIES=	sysutils
MASTER_SITES=	http://www.simon.org.ua/ipa/ \
		http://www.mirrors.wiretapped.net/security/network-monitoring/ipa/ \
		http://www.outloud.org/ipa/

MAINTAINER=	simon@simon.org.ua

NO_PACKAGE=	"Needs to be built uniquely for each host"
ALL_TARGET=	FreeBSD
.ifdef(NOPORTDOCS)
MAKE_ENV=	NOPORTDOCS="${NOPORTDOCS}"
.endif

MAN5=		ipa.5 ipa.conf.5
MAN8=		ipa.8 ipastat.8
MANLANG=	"" ru_RU.KOI8-R

.include <bsd.port.mk>
