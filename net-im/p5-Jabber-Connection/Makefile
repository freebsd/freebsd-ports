# Created by: Lars Eggert
# $FreeBSD$

PORTNAME=	Jabber-Connection
PORTVERSION=	0.04
CATEGORIES=	net-im perl5
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/
PKGNAMEPREFIX=	p5-

MAINTAINER=	lars.eggert@gmx.net
COMMENT=	Jabber Perl library for client/component connectivity

RUN_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser
BUILD_DEPENDS=	p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1

USES=		perl5
USE_PERL5=	configure

MAN3=		Jabber::Connection.3 Jabber::NS.3 Jabber::NodeFactory.3

NO_STAGE=	yes
.include <bsd.port.mk>
