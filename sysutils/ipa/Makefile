# New ports collection makefile for:	ipa
# Date created:				2 December 2000
# Whom:					Andrey Simonenko
#
# $FreeBSD$
#

PORTNAME=	ipa
PORTVERSION=	1.2.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.simon.org.ua/ipa/

MAINTAINER=	simon@simon.org.ua

NO_PACKAGE=	"Needs to be built uniquely for each site"
ALL_TARGET=	FreeBSD
.ifdef(NOPORTDOCS)
MAKE_ENV=	NOPORTDOCS="${NOPORTDOCS}"
.endif

MAN5=		ipa.5 ipa.conf.5
MAN8=		ipa.8 ipastat.8
MANLANG=	"" ru_RU.KOI8-R

.include <bsd.port.mk>
