# New ports collection makefile for:	p5-Jabber-Connection
# Date created:				01 October 2003
# Whom:	      				Lars Eggert
#
# $FreeBSD$
#

PORTNAME=	Jabber-Connection
PORTVERSION=	0.04
CATEGORIES=	net perl5
#MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
#MASTER_SITE_SUBDIR=	Jabber
MASTER_SITES=	http://www.pipetree.com/jabber/jabberconnection/
PKGNAMEPREFIX=	p5-

MAINTAINER=	lars.eggert@gmx.net
COMMENT=	Jabber Perl library for client/component connectivity

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser
BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1

PERL_CONFIGURE=	yes

MAN3=		Jabber::Connection.3 Jabber::NS.3 Jabber::NodeFactory.3

.include <bsd.port.mk>
