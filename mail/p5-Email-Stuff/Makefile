# New ports collection makefile for:	p5-Email-Stuff
# Date created:				12 Aug, 2009
# Whom:	      				Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Email-Stuff
PORTVERSION=	2.100
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wenheping@gmail.com
COMMENT=	A more casual approach to creating and sending Email

BUILD_DEPENDS=	p5-prefork>=1.01:${PORTSDIR}/devel/p5-prefork \
		p5-Params-Util>=0.23:${PORTSDIR}/devel/p5-Params-Util \
		p5-File-Type>=0.22:${PORTSDIR}/devel/p5-File-Type \
		p5-Email-Send>=2.185:${PORTSDIR}/mail/p5-Email-Send
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Email::Stuff.3

.include <bsd.port.mk>
