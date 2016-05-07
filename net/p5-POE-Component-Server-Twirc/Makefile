# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	POE-Component-Server-Twirc
PORTVERSION=	0.20
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Twitter/IRC gateway

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-AnyEvent>=0:devel/p5-AnyEvent \
		p5-AnyEvent-Twitter>=0:net/p5-AnyEvent-Twitter \
		p5-AnyEvent-Twitter-Stream>=0:net/p5-AnyEvent-Twitter-Stream \
		p5-Config-Any>=0:devel/p5-Config-Any \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
		p5-Log-Log4perl>=0:devel/p5-Log-Log4perl \
		p5-Moose>=0:devel/p5-Moose \
		p5-MooseX-Getopt>=0.15:devel/p5-MooseX-Getopt \
		p5-MooseX-Log-Log4perl>=0:devel/p5-MooseX-Log-Log4perl \
		p5-MooseX-POE>=0.215:devel/p5-MooseX-POE \
		p5-MooseX-SimpleConfig>=0:devel/p5-MooseX-SimpleConfig \
		p5-MooseX-Storage>=0:devel/p5-MooseX-Storage \
		p5-POE-Component-Server-IRC>=0.02005:irc/p5-POE-Component-Server-IRC \
		p5-POE-Component-TSTP>=0:devel/p5-POE-Component-TSTP \
		p5-POE-Loop-AnyEvent>=0:devel/p5-POE-Loop-AnyEvent \
		p5-Path-Class>=0:devel/p5-Path-Class \
		p5-Proc-Daemon>=0:devel/p5-Proc-Daemon \
		p5-Regexp-Common>=0:textproc/p5-Regexp-Common \
		p5-String-Truncate>=0:textproc/p5-String-Truncate \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -i '' -e '/auto_install/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
