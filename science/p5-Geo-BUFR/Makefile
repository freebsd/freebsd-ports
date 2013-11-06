# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Geo-BUFR
PORTVERSION=	1.25
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

.include <bsd.port.mk>
