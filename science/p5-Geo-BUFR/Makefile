# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Geo-BUFR
PORTVERSION=	1.24
CATEGORIES=	science perl5 geography
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PSANNES
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for handling of WMO BUFR files

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN1=		bufr_reencode.pl.1 \
		bufralter.pl.1 \
		bufrencode.pl.1 \
		bufrread.pl.1 \
		bufrresolve.pl.1
MAN3=		Geo::BUFR.3 \
		Geo::bufr_reencode.3 \
		Geo::bufralter.3 \
		Geo::bufrencode.3 \
		Geo::bufrread.3 \
		Geo::bufrresolve.3

.include <bsd.port.mk>
