# New ports collection makefile for:	p5-SNMP-Util
# Date created:				September 7 1999
# Whom:					Bill Fenner <fenner@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	SNMP-Util
PORTVERSION=	1.8
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	SNMP
PKGNAMEPREFIX=	p5-

MAINTAINER=	fenner@FreeBSD.org
COMMENT=	Perl modules to perform SNMP set,get,walk,next,walk_hash etc

#
# Define WITH_NETSNMP4 to use net-mgmt/net-snmp4 instead of net-mgmt/net-snmp.
#
.if !defined(WITH_NETSNMP4)
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/SNMP.pm:${PORTSDIR}/net-mgmt/net-snmp
EXTRA_PATCHES+=	${PATCHDIR}/extra-net-snmp-patch-Makefile.PL
.else
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/SNMP.pm:${PORTSDIR}/net-mgmt/p5-SNMP
.endif

PERL_CONFIGURE=	yes

MAN3=		SNMP::Util.3

.include <bsd.port.mk>
