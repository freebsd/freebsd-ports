# New ports collection makefile for:	www/p5-HTTP-Server-Simple-Static
# Date created:				30 March 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTTP-Server-Simple-Static
PORTVERSION=	0.07
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	HTTP
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Serve static files with HTTP::Server::Simple

RUN_DEPENDS=	p5-HTTP-Server-Simple>=0:${PORTSDIR}/www/p5-HTTP-Server-Simple \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-MIME-Types>=0:${PORTSDIR}/mail/p5-MIME-Types \
		p5-File-MMagic>=0:${PORTSDIR}/devel/p5-File-MMagic
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

MAN3=	HTTP::Server::Simple::Static.3

.include <bsd.port.mk>
