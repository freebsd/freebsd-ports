# New ports collection makefile for:	ipa
# Date created:				2 December 2000
# Whom:					Andrey Simonenko
#
# $FreeBSD$
#

PORTNAME=	ipa
PORTVERSION=	1.1.4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.simon.org.ua/ipa/

MAINTAINER=	simon@simon.org.ua

NO_PACKAGE=	"Needs to be built uniquely for each site"
ALL_TARGET=	FreeBSD

MAN5=		ipa.5 ipa.conf.5
MAN8=		ipa.8 ipastat.8
MANLANG=	"" ru_RU.KOI8-R

post-patch:
	@${PERL} -pi -ne "s|/usr/local/|${PREFIX}/|" \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
