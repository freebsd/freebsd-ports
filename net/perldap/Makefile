# New ports collection makefile for:	perldap
# Version required:	1.1b
# Date created:	17 May 1999
# Whom:		paul@freebsd.org
#
# $FreeBSD$
#

DISTNAME=	perldap-1_2_2
DISTFILES=	perldap-1.2.2.tgz
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.mozilla.org/pub/directory/perldap/

MAINTAINER=	paul@FreeBSD.org

WRKSRC=			${WRKDIR}/perldap
LIB_DEPENDS=	ldap.1:${PORTSDIR}/net/ldapsdk
                
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Mozilla::LDAP::Conn.3 \
			Mozilla::LDAP::LDIF.3 \
			Mozilla::LDAP::Utils.3 \
			Mozilla::LDAP::Entry.3 \
			Mozilla::LDAP::API.3

MAKE_ENV+= LDAPSDKDIR=${PREFIX}/mozilla/directory LDAPV3ON=yes LDAPSDKSSL=no

do-configure:
	@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL
 
.include <bsd.port.mk>
