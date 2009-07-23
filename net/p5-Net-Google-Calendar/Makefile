# New ports collection makefile for:	p5-Net-Google-Calendar
# Date created:		2006-05-15
# Whom:			Yi-Hsuan Hsin <mhsin@mhsin.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Google-Calendar
PORTVERSION=	0.97
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	mhsin@mhsin.org
COMMENT=	Programmatic access to Google's Calendar API

BUILD_DEPENDS=	p5-XML-Atom>=0:${PORTSDIR}/textproc/p5-XML-Atom \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-Net-Google-AuthSub>=0:${PORTSDIR}/net/p5-Net-Google-AuthSub
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	5.8.5+	# inherited from textproc/p5-XML-Atom

MAN3=		Net::Google::Calendar.3 Net::Google::Calendar::Base.3 \
		Net::Google::Calendar::Calendar.3 Net::Google::Calendar::Comments.3 \
		Net::Google::Calendar::Entry.3 Net::Google::Calendar::FeedLink.3 \
		Net::Google::Calendar::Person.3 Net::Google::Calendar::WebContent.3

.include <bsd.port.mk>
