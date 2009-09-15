# New ports collection makefile for:    p5-Authen-Bitcard
# Date created:				2007/01/16
# Whom:	      				chinsan
#
# $FreeBSD$
#

PORTNAME=	Authen-Bitcard
PORTVERSION=	0.87
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Bitcard authentication verification

BUILD_DEPENDS=	p5-Class-ErrorHandler>=0:${PORTSDIR}/devel/p5-Class-ErrorHandler \
		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-URI>=0:${PORTSDIR}/net/p5-URI

PERL_CONFIGURE=	yes

MAN3=	Authen::Bitcard.3

.include <bsd.port.mk>
