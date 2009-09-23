# New ports collection makefile for:	p5-Daemon-Generic
# Date created:		2008-05-30
# Whom:			BluePex Security Solutions <freebsd-ports@bluepex.com>
#
# $FreeBSD$
#

PORTNAME=	Daemon-Generic
PORTVERSION=	0.61
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	freebsd-ports@bluepex.com
COMMENT=	Framework to provide start/stop/reload for a daemon

RUN_DEPENDS=	p5-File-Flock>=0:${PORTSDIR}/devel/p5-File-Flock \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp

PERL_CONFIGURE=	yes

MAN3=	Daemon::Generic.3 \
	Daemon::Generic::Event.3 \
	Daemon::Generic::While1.3

.include <bsd.port.mk>
