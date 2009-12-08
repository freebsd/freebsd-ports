# New ports collection makefile for:	p5-SNMP-Util
# Date created:				September 7 1999
# Whom:					Bill Fenner <fenner@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	SNMP-Util
PORTVERSION=	1.8
PORTREVISION=	1
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl modules to perform SNMP set,get,walk,next,walk_hash etc

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/SNMP.pm:${PORTSDIR}/net-mgmt/net-snmp

EXTRA_PATCHES=	${PATCHDIR}/extra-net-snmp-patch-Makefile.PL

PERL_CONFIGURE=	yes

MAN3=		SNMP::Util.3

.include <bsd.port.mk>
