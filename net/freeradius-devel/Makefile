# New ports collection makefile for:	freeradius-devel
# Date created:		2001-03-13
# Whom:			wollman@lcs.mit.edu
#
# $FreeBSD$
#

PORTNAME=	freeradius-devel
PORTVERSION=	20010310
CATEGORIES=	net
# Copied from ftp://ftp.freeradius.org/pub/radius/CVS-snapshots/
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=wollman
DISTNAME=	freeradius-alpha-snapshot-${PORTVERSION}

MAINTAINER=	wollman@lcs.mit.edu

WRKSRC=		${WRKDIR}/freeradius-alpha-snapshot-${PORTVERSION}

USE_AUTOCONF_VER=213
USE_LIBTOOL=	YES
USE_GMAKE=	YES

MAN1=	radlast.1 radtest.1 raduse.1 radwho.1 radzap.1
MAN5=	acct_users.5 clients.5 dictionary.5 naslist.5 radiusd.conf.5 users.5
MAN8=	builddbm.8 radiusd.8 radwatch.8

#
# Figure most users will want these.  N.B.: if you change these,
# the packing list will be wrong.
#
STATIC_MODULES=	acct_unique always attr_filter detail dictionary \
		files mschap ns_mta_md5 pam preprocess radutmp realm unix

# Modules that still need work: counter ldap sql

CONFIGURE_ARGS=	--without-snmp --without-threads --localstatedir=/var \
		--with-static-modules="${STATIC_MODULES}" \
		--disable-ltdl-install

KRB5_MOD=	${WRKSRC}/src/modules/rlm_krb5

post-patch:
.if defined(WANT_KRB5) && defined(KRB5_HOME)
	@${MV} ${KRB5_MOD}/Makefile ${KRB5_MOD}/Makefile.orig
	@${SED} -e 's;^KRB5_LOCATION=.*$$;KRB5_LOCATION=${KRB5_HOME};' \
		< ${KRB5_MOD}/Makefile.orig > ${KRB5_MOD}/Makefile
.endif

#
# Installing these libraries is pointless since they are statically
# linked into the executable we installed.  It's easier to just
# delete them here rather than hacking the build system to not
# install them.
#
UNWANTED_LIBS=${STATIC_MODULES:S/^/lib\/rlm_/:S/$/.a/} \
	lib/rlm_example.a lib/rlm_fastusers.a lib/rlm_sql.a

post-install:
.if defined(WANT_KRB5) && defined(KRB5_HOME)
	@${RM} ${PREFIX}/lib/rlm_krb5.a
	@${ECHO} 'lib/rlm_krb5.so' >> ${TMPPLIST}
	@${ECHO} 'lib/rlm_krb5.so.0' >> ${TMPPLIST}
.endif
	@cd ${PREFIX} && ${RM} ${UNWANTED_LIBS}
.for f in acct_users attrs clients clients.conf hints huntgroups ldap.attrmap \
	naslist naspasswd proxy.conf radiusd.conf realms snmp.conf sql.conf \
	users
	@${MV} ${PREFIX}/etc/raddb/${f} ${PREFIX}/etc/raddb/${f}.sample
.endfor

# XXX should install an rc.d script.
# XXX should install some documentation.

.include <bsd.port.mk>
