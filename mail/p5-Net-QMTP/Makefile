# New ports collection makefile for:	mail/p5-Net-QMTP
# Date created:				15 October 2003
# Whom:					James Raftery <james@now.ie>
#
# $FreeBSD$
#

PORTNAME=	Net-QMTP
PORTVERSION=	0.06
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	james@now.ie
COMMENT=	Perl module to provide a Quick Mail Transfer Protocol (QMTP) client

BUILD_DEPENDS=	${SITE_PERL}/Text/Netstring.pm:${PORTSDIR}/textproc/p5-Text-Netstring
RUN_DEPENDS=	${SITE_PERL}/Text/Netstring.pm:${PORTSDIR}/textproc/p5-Text-Netstring

PERL_CONFIGURE=	yes

MAN3=		Net::QMTP.3

.include <bsd.port.mk>
