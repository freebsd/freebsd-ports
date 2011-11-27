# New ports collection makefile for:	p5-WebService-Dropbox
# Date created:		2011-11-25
# Whom:			Lung-Pin Chang <changlp@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	WebService-Dropbox
PORTVERSION=	0.03
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	changlp@cs.nctu.edu.tw
COMMENT=	Perl interface to Dropbox API

RUN_DEPENDS=	p5-Net-OAuth>=0:${PORTSDIR}/net/p5-Net-OAuth \
		p5-String-Random>=0:${PORTSDIR}/devel/p5-String-Random

PERL_CONFIGURE=	yes

MAN3=	WebService::Dropbox.3

.include <bsd.port.mk>
