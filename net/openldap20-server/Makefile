# New ports collection makefile for:    OpenLDAP 2.x
# Date created:		20 Sep 1998
# Whom:			Lachlan O'Dea
#
# $FreeBSD$
#

PORTNAME=	openldap
PORTVERSION=	2.0.21
CATEGORIES=	net databases
MASTER_SITES=	ftp://ftp.OpenLDAP.org/pub/OpenLDAP/%SUBDIR%/ \
		ftp://ftp.net.lut.ac.uk/openldap/%SUBDIR%/ \
		ftp://sunsite.cnlab-switch.ch/mirror/OpenLDAP/%SUBDIR%/ \
		ftp://mirror.aarnet.edu.au/pub/OpenLDAP/%SUBDIR%/ \
		ftp://gd.tuwien.ac.at/infosys/network/OpenLDAP/%SUBDIR%/ \
		http://www.unibase.cz/ldapcz/Programy/Free/OpenLDAP/%SUBDIR%/ \
		ftp://ftp.ntua.gr/mirror/OpenLDAP/%SUBDIR%/ \
		ftp://ftp.loxinfo.co.th/pub/unix/LDAP/OpenLDAP/%SUBDIR%/ \
		ftp://ftp.zcu.cz/pub/network/openldap/%SUBDIR%/
MASTER_SITE_SUBDIR=	openldap-release
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	db3.2:${PORTSDIR}/databases/db3

USE_AUTOCONF_VER=213
USE_LIBTOOL=	yes
USE_OPENSSL=	yes

LATEST_LINK=	openldap2

CONFIGURE_ARGS=	--localstatedir=/var/db \
		--with-threads \
		--enable-shared \
		--enable-dnssrv \
		--with-tls=openssl

# Include tcp-wrapper support
.if exists(/usr/include/tcpd.h)
CONFIGURE_ARGS+=	--enable-wrappers
.endif

# math.h uses _REENTRANT and stdio.h uses _THREAD_SAFE, so define both.
CPPFLAGS+=	-D_REENTRANT ${PTHREAD_CFLAGS} \
		-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/db3
LDFLAGS+=	-L${LOCALBASE}/lib

.if defined(WITH_SASL)
LIB_DEPENDS+=	sasl.8:${PORTSDIR}/security/cyrus-sasl
CPPFLAGS+=	-I${LOCALBASE}/include/sasl
.endif

.if defined(WITH_ODBC)
LIB_DEPENDS+=	iodbc.2:${PORTSDIR}/databases/libiodbc
CONFIGURE_ARGS+=--enable-sql
.endif

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"

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
		libexec/maildap \
		libexec/rcpt500 \
		libexec/rp500 \
		libexec/slapd \
		libexec/slurpd

.include <bsd.port.pre.mk>
.include "${FILESDIR}/manpages"

post-patch:
	@${PERL} -pi.fbsd -e 's@pidfile\t\t%LOCALSTATEDIR%/slapd.pid@pidfile\t\t/var/run/slapd.pid@g; \
		s@argsfile\t%LOCALSTATEDIR%/slapd.args@argsfile\t/var/run/slapd.args@g' ${WRKSRC}/servers/slapd/slapd.conf

post-configure:
	@cd ${WRKSRC} ; ${PATCH} < ${FILESDIR}/libtool.diff

pre-build:
	@cd ${WRKSRC} ; ${MAKE} depend

post-build:
	@${SED} 's,@@PREFIX@@,${PREFIX},g' ${FILESDIR}/slapd.sh >${WRKDIR}/slapd.sh

post-install:
.for f in ${BINS}
	@strip ${PREFIX}/${f}
.endfor
	@${INSTALL_SCRIPT} ${WRKDIR}/slapd.sh ${PREFIX}/etc/rc.d/slapd.sh.sample
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
