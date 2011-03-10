# New ports collection makefile for:	p5-Geo-BUFR
# Date created:      			March 10, 2011
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Geo-BUFR
PORTVERSION=	1.20
CATEGORIES=	science perl5 geography
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PSANNES
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Perl extension for handling of WMO BUFR files

RUN_DEPENDS=	p5-File-Slurp>0:${PORTSDIR}/devel/p5-File-Slurp

MAN1=		bufr_reencode.pl.1 \
		bufralter.pl.1 \
		bufrencode.pl.1 \
		bufrread.pl.1 \
		bufrresolve.pl.1
MAN3=		Geo::BUFR.3 \
		Geo::bufrresolve.3 \
		Geo::bufr_reencode.3 \
		Geo::bufrread.3 \
		Geo::bufralter.3 \
		Geo::bufrencode.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
