# New ports collection makefile for:	p5-WebService-Dropbox
# Date created:		2011-11-25
# Whom:			Lung-Pin Chang <changlp@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	WebService-Dropbox
PORTVERSION=	1.05
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ASKADNA
PKGNAMEPREFIX=	p5-

MAINTAINER=	changlp@cs.nctu.edu.tw
COMMENT=	Perl interface to Dropbox API

BUILD_DEPENDS=	p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-Net-OAuth>=0.27:${PORTSDIR}/net/p5-Net-OAuth \
		p5-String-Random>=0.22:${PORTSDIR}/devel/p5-String-Random
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS=	LWP	"Use LWP instead of Furl" off

PERL_CONFIGURE=	yes

MAN3=		WebService::Dropbox.3

.include <bsd.port.options.mk>

.if defined(WITH_LWP)
BUILD_DEPENDS+=	p5-LWP-Protocol-https>=6.02:${PORTSDIR}/www/p5-LWP-Protocol-https \
		p5-libwww>=6.02:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS+=	p5-LWP-Protocol-https>=6.02:${PORTSDIR}/www/p5-LWP-Protocol-https \
		p5-libwww>=6.02:${PORTSDIR}/www/p5-libwww
.else
BUILD_DEPENDS+=	p5-Furl>=0.38:${PORTSDIR}/www/p5-Furl
RUN_DEPENDS+=	p5-Furl>=0.38:${PORTSDIR}/www/p5-Furl
.endif

.include <bsd.port.mk>
