# New ports collection makefile for:	perldap
# Date created:	17 May 1999
# Whom:		paul@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	perldap
PORTVERSION=	1.4.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	directory/perldap
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	paul@FreeBSD.org

LIB_DEPENDS=	mozldap.1:${PORTSDIR}/net/ldapsdk

WRKSRC=		${WRKDIR}/$(PORTNAME)-$(PORTVERSION)
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Mozilla::LDAP::Conn.3 \
			Mozilla::LDAP::LDIF.3 \
			Mozilla::LDAP::Utils.3 \
			Mozilla::LDAP::Entry.3 \
			Mozilla::LDAP::API.3

MAKE_ENV+= LDAPSDKDIR=${PREFIX} LDAPV3ON=yes LDAPSDKSSL=no

do-configure:
	@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
