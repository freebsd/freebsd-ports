# New ports collection makefile for:	p5-SNMP
# Date created:				May 5th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	SNMP
PORTVERSION=	4.2.0
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	SNMP
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A perl5 module for interfacing with the CMU SNMP library

LIB_DEPENDS=	snmp.4:${PORTSDIR}/net-mgmt/net-snmp4

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 500800
BROKEN=		"Does not build with perl >=5.8"
.endif

post-install:
		@${INSTALL_DATA} ${WRKSRC}/README \
			${PREFIX}/lib/perl5/site_perl/README.SNMP

.include <bsd.port.post.mk>
