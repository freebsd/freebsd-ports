# New ports collection makefile for:    OpenLDAP 1.x
# Date created:		20 Sep 1998
# Whom:			Lachlan O'Dea
#
# $FreeBSD$
#

PORTNAME=	openldap12
PORTVERSION=	1.2.13
CATEGORIES=	net databases
MASTER_SITES=	ftp://ftp.OpenLDAP.org/pub/OpenLDAP/%SUBDIR%/ \
		http://www.PlanetMirror.com/pub/openldap/%SUBDIR%/ \
		ftp://gd.tuwien.ac.at/infosys/network/OpenLDAP/%SUBDIR%/ \
		ftp://ftp.matrix.com.br/pub/openldap/%SUBDIR%/ \
		ftp://ftp.ucr.ac.cr/pub/Unix/openldap/%SUBDIR%/ \
		ftp://ftp.ntua.gr/mirror/OpenLDAP/%SUBDIR%/ \
		ftp://ftp.dti.ad.jp/pub/net/OpenLDAP/%SUBDIR%/ \
		ftp://ftp.u-aizu.ac.jp/pub/net/openldap/%SUBDIR%/ \
		ftp://ftp.holywar.net/pub/OpenLDAP/%SUBDIR%/ \
		ftp://ftp.nl.uu.net/pub/unix/db/openldap/%SUBDIR%/ \
		ftp://ftp.linux.pt/pub/mirrors/OpenLDAP/%SUBDIR%/ \
		ftp://ftp.si.uniovi.es/mirror/OpenLDAP/%SUBDIR%/ \
		ftp://sunsite.cnlab-switch.ch/mirror/OpenLDAP/%SUBDIR%/ \
		ftp://ftp.plig.org/pub/OpenLDAP/%SUBDIR%/
MASTER_SITE_SUBDIR=	openldap-release
DISTNAME=	openldap-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	lodea@vet.com.au
COMMENT=	Open source LDAP client and server software

BROKEN=		ancient, unsupported, potential security issues

USE_LIBTOOL=	yes

CONFIGURE_ARGS=	--localstatedir=/var/db \
		--enable-shared \
		--enable-dns

# Include tcp-wrapper support
.if exists(/usr/include/tcpd.h)
CONFIGURE_ARGS+=	--enable-wrappers
.endif

.if defined(WITH_DB2)
BUILD_DEPENDS=	${LOCALBASE}/lib/libdb2.a:${PORTSDIR}/databases/db2

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/db2 ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=	--enable-ldbm \
			--with-ldbm-api=db2
.endif

INSTALLS_SHLIB=	yes

BINS=		bin/ldapadd \
		bin/ldapdelete \
		bin/ldapmodify \
		bin/ldapmodrdn \
		bin/ldappasswd \
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
		sbin/ldif2ldbm

.include <bsd.port.pre.mk>
.include "${FILESDIR}/manpages"

pre-build:
	cd ${WRKSRC} ; ${MAKE} depend

post-build:
	${SED} 's,@@PREFIX@@,${PREFIX},g' ${FILESDIR}/slapd.sh >${WRKDIR}/slapd.sh

post-install:
.for f in ${BINS}
	${STRIP_CMD} ${PREFIX}/${f}
.endfor
	${INSTALL_SCRIPT} ${WRKDIR}/slapd.sh ${PREFIX}/etc/rc.d/slapd.sh.sample

.include <bsd.port.post.mk>
