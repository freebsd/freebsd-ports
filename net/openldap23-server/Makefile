# New ports collection makefile for:    openldap
# Date created:         20 Sep 1998
# Whom:                 Lachlan O'Dea
#
# $FreeBSD$
#

PORTNAME=	openldap
PORTVERSION=	1.2.11
PORTREVISION=	1
CATEGORIES=	net databases
MASTER_SITES=	ftp://ftp.OpenLDAP.org/pub/OpenLDAP/openldap-release/ \
		ftp://ftp.net.lut.ac.uk/openldap/openldap-release/ \
		ftp://sunsite.cnlab-switch.ch/mirror/OpenLDAP/openldap-release/ \
		ftp://mirror.aarnet.edu.au/pub/OpenLDAP/openldap-release/ \
		ftp://gd.tuwien.ac.at/infosys/network/OpenLDAP/openldap-release/ \
		http://www.unibase.cz/ldapcz/Programy/Free/OpenLDAP/openldap-release/ \
		ftp://ftp.ntua.gr/mirror/OpenLDAP/openldap-release/ \
		ftp://ftp.loxinfo.co.th/pub/unix/LDAP/OpenLDAP/openldap-release/\
		ftp://ftp.zcu.cz/pub/network/openldap/openldap-release/
EXTRACT_SUFX=	.tgz

MAINTAINER=	lodea@vet.com.au

.if defined(WITH_DB2)
BUILD_DEPENDS=	${LOCALBASE}/lib/libdb2.a:${PORTSDIR}/databases/db/
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/db2 -D_THREAD_SAFE" \
		LDFLAGS=-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--enable-ldbm --with-ldbm-api=db2
.endif

USE_LIBTOOL=	yes
CONFIGURE_ARGS+=	--localstatedir=/var/run --enable-shared --enable-dns

# Include tcp-wrapper support
.if exists(/usr/include/tcpd.h)
CONFIGURE_ARGS+= --enable-wrappers
.endif

BINS=		bin/ldapadd \
		bin/ldapdelete \
		bin/ldapmodrdn \
		bin/ldapsearch \
		bin/ud \
		libexec/fax500 \
		libexec/go500 \
		libexec/go500gw \
		libexec/in.xfingerd \
		libexec/mail500 \
		libexec/rcpt500 \
		libexec/rp500 \
		libexec/slapd \
		libexec/slurpd \
		sbin/centipede \
		sbin/ldbmcat \
		sbin/ldbmtest \
		sbin/ldif \
		sbin/ldif2id2children \
		sbin/ldif2id2entry \
		sbin/ldif2index \
		sbin/ldif2ldbm \
		bin/ldapmodify \
		bin/ldappasswd

.include <bsd.port.pre.mk>
.include "${FILESDIR}/manpages"

pre-build:
	cd ${WRKSRC} ; ${MAKE} depend

post-build:
	${SED} 's,@@PREFIX@@,${PREFIX},g' ${FILESDIR}/slapd.sh >${WRKDIR}/slapd.sh

post-install:
.for f in ${BINS}
	strip ${PREFIX}/${f}
.endfor
	${INSTALL_SCRIPT} ${WRKDIR}/slapd.sh ${PREFIX}/etc/rc.d/slapd.sh.sample

.include <bsd.port.post.mk>
