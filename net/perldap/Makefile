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
COMMENT=	Perl interface to LDAP

LIB_DEPENDS=	mozldap.1:${PORTSDIR}/net/ldapsdk

PERL_CONFIGURE=	yes
CONFIGURE_ENV+=	LDAPSDKDIR=${PREFIX} LDAPV3ON=yes LDAPSDKSSL=no
MAKE_ENV=	${CONFIGURE_ENV}

MAN3=	Mozilla::LDAP::Conn.3 \
	Mozilla::LDAP::LDIF.3 \
	Mozilla::LDAP::Utils.3 \
	Mozilla::LDAP::Entry.3 \
	Mozilla::LDAP::API.3

.include <bsd.port.mk>
