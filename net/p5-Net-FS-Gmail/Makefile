# New ports collection makefile for:	p5-Net-FS-Gmail
# Date created:		2006-07-20
# Whom:			Tsung-Han Yeh <snowfly@yuntech.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Net-FS-Gmail
PORTVERSION=	0.2
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	A Perl interface for store and retrieve files on Gmail

BUILD_DEPENDS=	p5-Mail-Webmail-Gmail>=0:${PORTSDIR}/mail/p5-Mail-Webmail-Gmail \
		p5-Time-modules>=0:${PORTSDIR}/devel/p5-Time-modules \
		p5-URI>=0:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN1=		gmailfs.1
MAN3=		Net::FS::Gmail.3

.include <bsd.port.mk>
