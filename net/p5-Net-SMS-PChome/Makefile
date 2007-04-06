# New ports collection makefile for:	p5-Net-SMS-PChome
# Date created:		2007-04-05
# Whom:			Tsung-Han Yeh <snowfly@yuntech.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Net-SMS-PChome
PORTVERSION=	0.11
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	Send SMS messages via the sms.pchome.com.tw service

BUILD_DEPENDS=	${SITE_PERL}/WWW/Mechanize.pm:${PORTSDIR}/www/p5-WWW-Mechanize \
		${SITE_PERL}/HTML/TagParser.pm:${PORTSDIR}/www/p5-HTML-TagParser \
		${SITE_PERL}/${PERL_ARCH}/Date/Calc.pm:${PORTSDIR}/devel/p5-Date-Calc
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::SMS::PChome.3

.include <bsd.port.mk>
