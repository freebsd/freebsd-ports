# New ports collection makefile for:    openldap
# Version required:     1.2.0
# Date created:         20 Sep 1998
# Whom:                 Lachlan O'Dea
#
# $Id: Makefile,v 1.4 1999/01/04 15:49:04 dirk Exp $
#

DISTNAME=	openldap-1.2.0
CATEGORIES=	net databases
MASTER_SITES=	ftp://ftp.OpenLDAP.org/pub/OpenLDAP/openldap-release/ \
		ftp://ftp.net.lut.ac.uk/openldap/openldap-release/ \
		ftp://sunsite.cnlab-switch.ch/mirror/OpenLDAP/openldap-release/ \
		ftp://mirror.aarnet.edu.au/pub/OpenLDAP/openldap-release/
EXTRACT_SUFX=	.tgz

MAINTAINER=     ulmo@earthling.net

WRKSRC=		${WRKDIR}/ldap
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>
.include "${FILESDIR}/manpages"

pre-build:
	cd ${WRKSRC} ; make depend

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
	${PREFIX}/sbin/ldif2index ${PREFIX}/sbin/ldif2ldbm \
	${PREFIX}/bin/ldapmodify ${PREFIX}/bin/ldappasswd

.include <bsd.port.post.mk>
