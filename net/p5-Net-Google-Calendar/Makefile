# New ports collection makefile for:	p5-Net-Google-Calendar
# Date created:		2006-05-15
# Whom:			Yi-Hsuan Hsin <mhsin@mhsin.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Google-Calendar
DISTVERSION=	0.5
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	mhsin@mhsin.org
COMMENT=	Programmatic access to Google's Calendar API

BUILD_DEPENDS=	p5-XML-Atom>=0:${PORTSDIR}/textproc/p5-XML-Atom \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Net::Google::Calendar.3 Net::Google::Calendar::Entry.3 \
		Net::Google::Calendar::Person.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500805 # inherited from textproc/p5-XML-Atom
IGNORE=	requires at least Perl 5.8.5.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
