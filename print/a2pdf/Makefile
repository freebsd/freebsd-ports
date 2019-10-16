# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	a2pdf
PORTVERSION=	1.13
PORTREVISION=	2
CATEGORIES=	print perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JONALLEN

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Text to PDF converter

LICENSE=	ART20

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-File-Type>=0:devel/p5-File-Type \
		p5-Image-Size>=0:graphics/p5-Image-Size \
		p5-PDF-API2>=0:textproc/p5-PDF-API2 \
		p5-Switch>=0:lang/p5-Switch \
		perltidy:devel/p5-Perl-Tidy

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
