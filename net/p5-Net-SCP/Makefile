# New ports collection makefile for:   p5-Net-SCP
# Date created:                                12 May 2002
# Whom:                                        Erich Zigler <erich@tacni.net>
#
# $FreeBSD$
#

PORTNAME=	Net-SCP
PORTVERSION=	0.06
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	erich@tacni.net

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Net/SSH.pm:${PORTSDIR}/net/p5-Net-SSH \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/String/ShellQuote.pm:${PORTSDIR}/textproc/p5-String-ShellQuote
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::SCP.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
