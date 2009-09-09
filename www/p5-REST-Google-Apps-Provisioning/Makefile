# New ports collection makefile for:	p5-REST-Google-Apps-Provisioning
# Date created:		2009-08-06
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	REST-Google-Apps-Provisioning
PORTVERSION=	1.1.3
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	REST
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A Perl library to Google\'s RESTful Apps API

RUN_DEPENDS=	p5-XML-Simple>0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-libwww>0:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN3=		REST::Google::Apps::Provisioning.3

.include <bsd.port.mk>
