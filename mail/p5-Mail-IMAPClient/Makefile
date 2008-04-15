# New ports collection makefile for:	p5-Mail-IMAPClient
# Date created:		14 Nov 2000
# Whom:			TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	Mail-IMAPClient
PORTVERSION=	3.06
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module to talk to a IMAP4rev1 (RFC2060) server

BUILD_DEPENDS=	p5-Parse-RecDescent>=1.94:${PORTSDIR}/devel/p5-Parse-RecDescent \
		p5-Digest-HMAC>0:${PORTSDIR}/security/p5-Digest-HMAC
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=</dev/null

INSTALL_TARGET=	pure_site_install

MAN3=	Mail::IMAPClient.3 \
	Mail::IMAPClient::BodyStructure.3 \
	Mail::IMAPClient::BodyStructure::Parse.3 \
	Mail::IMAPClient::MessageSet.3 \
	Mail::IMAPClient::Thread.3

.include <bsd.port.mk>
