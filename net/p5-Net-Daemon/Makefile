# New ports collection makefile for:	p5-Net-Daemon
# Date created:				27 Feb 2000
# Whom:	      				Vanilla I. Shu <vanilla@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	Net-Daemon
PORTVERSION=	0.43
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Perl5 extension for portable daemons

PERL_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

MAN3=		Net::Daemon.3 \
		Net::Daemon::Log.3 \
		Net::Daemon::Test.3

post-patch:
	@${FIND} ${WRKSRC} -name ".svn" | ${XARGS} ${RM} -rf

.include <bsd.port.mk>
