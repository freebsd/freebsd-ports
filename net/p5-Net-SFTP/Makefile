# New ports collection makefile for:	Net-SFTP
# Date created:				08 Oct 2003
# Whom:					Trevor Corpropst <tcornpropst@cox.net>
#
# $FreeBSD$
#

PORTNAME=	Net-SFTP
PORTVERSION=	0.05
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	tcornpropst@cox.net
COMMENT=	Perl5 module implementing Secure File Transfer Protocol client

BUILD_DEPENDS=	${SITE_PERL}/Net/SSH/Perl.pm:${PORTSDIR}/net/p5-Net-SSH-Perl
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::SFTP.3 \
		Net::SFTP::Attributes.3 \
		Net::SFTP::Buffer.3 \
		Net::SFTP::Constants.3 \
		Net::SFTP::Util.3

.include <bsd.port.mk>
