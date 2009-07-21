# New ports collection makefile for:	p5-POE-Component-Server-NNTP
# Date created:		2007-02-23
# Whom:			Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Server-NNTP
PORTVERSION=	1.04
CATEGORIES=	news perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A component that provides NNTP server functionality

RUN_DEPENDS=	p5-POE>=0.38:${PORTSDIR}/devel/p5-POE \
		p5-POE-Component-Pluggable>=0.03:${PORTSDIR}/devel/p5-POE-Component-Pluggable \
		p5-POE-Component-Client-NNTP>=1.05:${PORTSDIR}/news/p5-POE-Component-Client-NNTP

PERL_CONFIGURE=	yes

MAN3=		POE::Component::Server::NNTP.3 \
		POE::Component::Server::NNTP::Constants.3

.include <bsd.port.mk>
