# New ports collection makefile for:	p5-SNMP
# Date created:				May 5th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	SNMP
PORTVERSION=	4.2.6
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ucd-snmp.ucdavis.edu/ \
		ftp://sunsite.cnlab-switch.ch/mirror/ucd-snmp/ \
		ftp://ftp.win.ne.jp/pub/network/snmp/ucd-snmp/
MASTER_SITE_SUBDIR=	net-snmp
PKGNAMEPREFIX=	p5-
DISTNAME=	ucd-snmp-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A perl5 module for interfacing with the CMU SNMP library

LIB_DEPENDS=	snmp.4:${PORTSDIR}/net-mgmt/net-snmp4

WRKSRC=		${WRKDIR}/${DISTNAME}/perl/SNMP

PERL_CONFIGURE=	yes

post-install:
		@${INSTALL_DATA} ${WRKSRC}/README \
			${PREFIX}/lib/perl5/site_perl/README.SNMP

.include <bsd.port.mk>
