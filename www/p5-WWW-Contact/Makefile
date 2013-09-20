# Created by: Fred Cox
# $FreeBSD$

PORTNAME=	WWW-Contact
PORTVERSION=	0.47
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:FAYLAND
PKGNAMEPREFIX=	p5-

MAINTAINER=	sailorfred@yahoo.com
COMMENT=	Contact importer for all the major email systems

LICENSE=	ART20 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Crypt-SSLeay>=0:${PORTSDIR}/security/p5-Crypt-SSLeay \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-HTML-TokeParser-Simple>=0:${PORTSDIR}/www/p5-HTML-TokeParser-Simple \
		p5-HTML-Tree>=0:${PORTSDIR}/www/p5-HTML-Tree \
		p5-JSON-XS>=0:${PORTSDIR}/converters/p5-JSON-XS \
		p5-Moose>=0.77:${PORTSDIR}/devel/p5-Moose \
		p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS \
		p5-Net-Google-AuthSub>=0:${PORTSDIR}/net/p5-Net-Google-AuthSub \
		p5-Text-vCard>=0:${PORTSDIR}/textproc/p5-Text-vCard \
		p5-WWW-Mechanize>=0:${PORTSDIR}/www/p5-WWW-Mechanize \
		p5-WWW-Mechanize-GZip>=0:${PORTSDIR}/www/p5-WWW-Mechanize-GZip
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		WWW::Contact.3 \
		WWW::Contact::AOL.3 \
		WWW::Contact::BG::Abv.3 \
		WWW::Contact::BG::Mail.3 \
		WWW::Contact::Base.3 \
		WWW::Contact::CN::163.3 \
		WWW::Contact::Gmail.3 \
		WWW::Contact::GoogleContactsAPI.3 \
		WWW::Contact::Hotmail.3 \
		WWW::Contact::Indiatimes.3 \
		WWW::Contact::Lycos.3 \
		WWW::Contact::Mail.3 \
		WWW::Contact::Plaxo.3 \
		WWW::Contact::Rediffmail.3 \
		WWW::Contact::Yahoo.3

NO_STAGE=	yes
.include <bsd.port.mk>
