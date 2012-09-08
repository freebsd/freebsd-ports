# New ports collection makefile for:	p5-Daemon-Generic
# Date created:		2008-05-30
# Whom:			BluePex Security Solutions <freebsd-ports@bluepex.com>
#
# $FreeBSD$
#

PORTNAME=	Daemon-Generic
PORTVERSION=	0.82
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Framework to provide start/stop/reload for a daemon

BUILD_DEPENDS=	p5-File-Flock>=0:${PORTSDIR}/devel/p5-File-Flock \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-AnyEvent>=0:${PORTSDIR}/devel/p5-AnyEvent \
		p5-Event>=0:${PORTSDIR}/devel/p5-Event \
		p5-Eval-LineNumbers>=0:${PORTSDIR}/devel/p5-Eval-LineNumbers
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Daemon::Generic.3 \
	Daemon::Generic::Event.3 \
	Daemon::Generic::While1.3 \
	Daemon::Generic::AnyEvent.3

.include <bsd.port.mk>
