# New ports collection makefile for:	junipoll
# Date created:				Tue Jun 17 17:28:52 PDT 2003
# Whom:					Bill Fumerola <billf@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	junipoll
PORTVERSION=	1.015
CATEGORIES=	net perl5
MASTER_SITES=	http://net.doit.wisc.edu/~plonka/junipoll/
MASTER_SITE_SUBDIR=	. old

MAINTAINER=	billf@FreeBSD.org
COMMENT=	JUNIper router snmp POLLer for firewall filter counters

RUN_DEPENDS=	rrdtool:${PORTSDIR}/net/rrdtool \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Altoids.pm:${PORTSDIR}/net/p5-Altoids

PERL_CONFIGURE=	yes

MAN1=		junipoll.1

.include <bsd.port.mk>
