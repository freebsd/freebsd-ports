# New ports collection makefile for:    ldap2dns
# Date created:         29 September 2003
# Whom:                 Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=       ldap2dns
PORTVERSION=    0.3.1
PORTREVISION=	1
CATEGORIES=     net
MASTER_SITES=   http://ldap2dns.tiscover.com/

MAINTAINER=     bms@FreeBSD.org
COMMENT=	Maintain DNS zones using an LDAP directory

WITH_OPENLDAP_VER?=	12
.if ${WITH_OPENLDAP_VER} == "21"
LIB_DEPENDS=	ldap.2:${PORTSDIR}/net/openldap21-client
.elif ${WITH_OPENLDAP_VER} == "20"
LIB_DEPENDS=	ldap.2:${PORTSDIR}/net/openldap20-client
.elif ${WITH_OPENLDAP_VER} == "12"
LIB_DEPENDS=	ldap.1:${PORTSDIR}/net/openldap12
.endif

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS \
		${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap

USE_GMAKE=yes
USE_PERL5=yes

MAKE_ENV+=PREFIX=$(PREFIX)
MAKE_ENV+=INC=-I$(PREFIX)/include
MAKE_ENV+=LIB=-L$(PREFIX)/lib

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/ldap2dns ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ldap2dnsd ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/dns.schema ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/example.ldif ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/README.html ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/ldap2tinydns-conf ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/import.pl ${DATADIR}

.include <bsd.port.mk>
