# New ports collection makefile for:    openldap
# Version required:     1.0.1
# Date created:         20 Sep 1998
# Whom:                 Lachlan O'Dea
#
# $Id$
#

DISTNAME=       openldap-1.0.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.OpenLDAP.org/pub/OpenLDAP/
EXTRACT_SUFX=	.tgz

MAINTAINER=     ulmo@earthling.net

WRKSRC=		${WRKDIR}/ldap
MANCOMPRESSED=	yes

.include "files/manpages"

MAKE_ENV=	LDAP_PREFIX=${PREFIX} \
		EXTRACFLAGS="${CFLAGS}"

pre-patch:
	${CP} ${WRKSRC}/Make-common.dist ${WRKSRC}/Make-common

post-install:
	strip ${PREFIX}/bin/ldapadd ${PREFIX}/bin/ldapdelete \
	${PREFIX}/bin/ldapmodrdn ${PREFIX}/bin/ldapsearch ${PREFIX}/bin/ud \
	${PREFIX}/libexec/fax500 ${PREFIX}/libexec/go500 \
	${PREFIX}/libexec/go500gw ${PREFIX}/libexec/in.xfingerd \
	${PREFIX}/libexec/mail500 ${PREFIX}/libexec/rcpt500 \
	${PREFIX}/libexec/rp500 ${PREFIX}/libexec/slapd \
	${PREFIX}/libexec/slurpd ${PREFIX}/sbin/centipede \
	${PREFIX}/sbin/ldbmcat ${PREFIX}/sbin/ldbmtest ${PREFIX}/sbin/ldif \
	${PREFIX}/sbin/ldif2id2children ${PREFIX}/sbin/ldif2id2entry \
	${PREFIX}/sbin/ldif2index ${PREFIX}/sbin/ldif2ldbm

.include <bsd.port.mk>
