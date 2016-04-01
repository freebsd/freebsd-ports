# Created by: Bill Fenner <fenner@FreeBSD.org>
# $FreeBSD$

PORTNAME=	SNMP-Util
PORTVERSION=	1.8
PORTREVISION=	2
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl modules to perform SNMP set,get,walk,next,walk_hash etc

RUN_DEPENDS=	net-snmp>=0:net-mgmt/net-snmp

EXTRA_PATCHES=	${PATCHDIR}/extra-net-snmp-patch-Makefile.PL

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
