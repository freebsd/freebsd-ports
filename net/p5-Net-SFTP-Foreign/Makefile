# New ports collection makefile for:	Net-SFTP-Foreign
# Date created:				27 Jun 2006
# Whom:					Simun Mikecin <numisemis@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	Net-SFTP-Foreign
PORTVERSION=	1.53
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	numisemis@yahoo.com
COMMENT=	Net::SFTP::Foreign - Secure File Transfer Protocol client

BUILD_DEPENDS+=	${SITE_PERL}/File/Which.pm:${PORTSDIR}/sysutils/p5-File-Which \
		${SITE_PERL}/${PERL_ARCH}/Sort/Key.pm:${PORTSDIR}/devel/p5-Sort-Key
RUN_DEPENDS+=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=		Net::SFTP::Foreign.3 \
		Net::SFTP::Foreign::Attributes.3 \
		Net::SFTP::Foreign::Attributes::Compat.3 \
		Net::SFTP::Foreign::Buffer.3 \
		Net::SFTP::Foreign::Compat.3 \
		Net::SFTP::Foreign::Constants.3 \
		Net::SFTP::Foreign::Local.3

.include <bsd.port.mk>
