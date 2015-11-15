# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	a2pdf
PORTVERSION=	1.13
PORTREVISION=	2
CATEGORIES=	print perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JONALLEN

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text to PDF converter

LICENSE=	ART20

BUILD_DEPENDS=	p5-PDF-API2>=0:${PORTSDIR}/textproc/p5-PDF-API2 \
		p5-Switch>=0:lang/p5-Switch \
		perltidy:${PORTSDIR}/devel/p5-Perl-Tidy \
		p5-Image-Size>=0:${PORTSDIR}/graphics/p5-Image-Size \
		p5-File-Type>=0:${PORTSDIR}/devel/p5-File-Type
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
