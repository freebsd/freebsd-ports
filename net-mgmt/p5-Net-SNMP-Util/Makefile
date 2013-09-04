# New ports collection makefile for:	p5-Net-SNMP-Util
# Date created:		2011-03-29
# Whom:			Hsin-Han You <hhyou@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Net-SNMP-Util
PORTVERSION=	1.04
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TONODERA
PKGNAMEPREFIX=	p5-

MAINTAINER=	hhyou@cs.nctu.edu.tw
COMMENT=	Utility functions for Net::SNMP

RUN_DEPENDS=	p5-Net-SNMP>=0:${PORTSDIR}/net-mgmt/p5-Net-SNMP \
	        p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils

USES=		perl5
USE_PERL5=	configure

MAN3=		Net::SNMP::Util.3 Net::SNMP::Util::OID.3 Net::SNMP::Util::TC.3

.include <bsd.port.mk>
