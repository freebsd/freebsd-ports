# Created by: Fred Cox
# $FreeBSD$

PORTNAME=	WWW-Contact
PORTVERSION=	0.47
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:FAYLAND
PKGNAMEPREFIX=	p5-

MAINTAINER=	sailorfred@yahoo.com
COMMENT=	Contact importer for all the major email systems

LICENSE=	ART20 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Crypt-SSLeay>=0:security/p5-Crypt-SSLeay \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-HTML-TokeParser-Simple>=0:www/p5-HTML-TokeParser-Simple \
		p5-HTML-Tree>=0:www/p5-HTML-Tree \
		p5-JSON-XS>=0:converters/p5-JSON-XS \
		p5-Moose>=0.77:devel/p5-Moose \
		p5-Net-DNS>=0:dns/p5-Net-DNS \
		p5-Net-Google-AuthSub>=0:net/p5-Net-Google-AuthSub \
		p5-Text-vCard>=0:textproc/p5-Text-vCard \
		p5-WWW-Mechanize>=0:www/p5-WWW-Mechanize \
		p5-WWW-Mechanize-GZip>=0:www/p5-WWW-Mechanize-GZip
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
