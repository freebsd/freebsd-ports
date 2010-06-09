# New ports collection makefile for:	p5-WWW-Contact
# Date created:				2010/02/22
# Whom:					Fred Cox
#
# $FreeBSD$
#

PORTNAME=	WWW-Contact
PORTVERSION=	0.38
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/F/FA/FAYLAND/
PKGNAMEPREFIX=	p5-

MAINTAINER=	sailorfred@yahoo.com
COMMENT=	Contact importer for all the major email systems

RUN_DEPENDS=	${SITE_PERL}/HTML/TokeParser/Simple.pm:${PORTSDIR}/www/p5-HTML-TokeParser-Simple \
		${SITE_PERL}/WWW/Mechanize.pm:${PORTSDIR}/www/p5-WWW-Mechanize \
		${SITE_PERL}/HTML/TreeBuilder.pm:${PORTSDIR}/www/p5-HTML-Tree \
		${SITE_PERL}/${PERL_ARCH}/JSON/XS.pm:${PORTSDIR}/converters/p5-JSON-XS \
		${SITE_PERL}/Text/vCard/Addressbook.pm:${PORTSDIR}/textproc/p5-Text-vCard \
		${SITE_PERL}/WWW/Mechanize/GZip.pm:${PORTSDIR}/www/p5-WWW-Mechanize-GZip \
		${SITE_PERL}/Net/Google/AuthSub.pm:${PORTSDIR}/net/p5-Net-Google-AuthSub \
		${SITE_PERL}/${PERL_ARCH}/Crypt/SSLeay.pm:${PORTSDIR}/security/p5-Crypt-SSLeay \
		${SITE_PERL}/${PERL_ARCH}/Moose.pm:${PORTSDIR}/devel/p5-Moose

PERL_CONFIGURE=	yes
USE_PERL5=	yes

MAN3=	WWW::Contact.3 \
	WWW::Contact::Base.3 \
	WWW::Contact::Plaxo.3\
	WWW::Contact::Rediffmail.3 \
	WWW::Contact::CN::163.3 \
	WWW::Contact::GoogleContactsAPI.3 \
	WWW::Contact::Lycos.3 \
	WWW::Contact::Yahoo.3 \
	WWW::Contact::Indiatimes.3 \
	WWW::Contact::BG::Abv.3 \
	WWW::Contact::BG::Mail.3 \
	WWW::Contact::Mail.3 \
	WWW::Contact::Hotmail.3 \
	WWW::Contact::AOL.3 \
	WWW::Contact::Gmail.3

.include <bsd.port.mk>
