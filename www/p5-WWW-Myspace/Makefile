# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	WWW-Myspace
PORTVERSION=	0.92
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Access MySpace.com profile information from Perl

RUN_DEPENDS=	p5-Config-General>=0:${PORTSDIR}/devel/p5-Config-General \
		p5-Contextual-Return>=0:${PORTSDIR}/devel/p5-Contextual-Return \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-Spiffy>=0.24:${PORTSDIR}/devel/p5-Spiffy \
		p5-Time-modules>=100.010301:${PORTSDIR}/devel/p5-Time-modules \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-WWW-Mechanize>=1.2:${PORTSDIR}/www/p5-WWW-Mechanize \
		p5-YAML>=0.39:${PORTSDIR}/textproc/p5-YAML \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww

USES=		perl5
USE_PERL5=	configure

MAN1=		approve_friends.1 comment_myspace.1 \
		message_group.1
MAN3=		WWW::Myspace.3 WWW::Myspace::Comment.3 \
		WWW::Myspace::FriendChanges.3 \
		WWW::Myspace::Message.3 WWW::Myspace::MyBase.3

.include <bsd.port.mk>
