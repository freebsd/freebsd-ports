# New ports collection makefile for:	cyrus-sasl
# Date created:				Nov 1 1999
# Whom:					hetzels@westbend.net
#
# $FreeBSD$
#

PORTNAME=	cyrus-sasl
PORTVERSION=	1.5.24
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/ \
		${MASTER_SITE_LOCAL} \
		ftp://ftp.hanse.de/sites/transit/mirror/ftp.andrew.cmu.edu/pub/cyrus-mail/
MASTER_SITE_SUBDIR=	stb/mirror/ftp.andrew.cmu.edu/pub/cyrus-mail

MAINTAINER=	hetzels@westbend.net

USE_OPENSSL=	YES

INSTALLS_SHLIB=	yes

MAN3=		sasl.3 sasl_authorize_t.3 sasl_callbacks.3 sasl_checkpass.3 \
		sasl_client_init.3 sasl_client_new.3 sasl_client_start.3 sasl_client_step.3 \
		sasl_decode.3 sasl_done.3 sasl_encode.3 sasl_errstring.3 sasl_getopt_t.3 \
		sasl_getpath_t.3 sasl_getprop.3 sasl_getsecret_t.3 sasl_getsimple_t.3 \
		sasl_listmech.3 sasl_log_t.3 \
		sasl_server_init.3 sasl_server_new.3 sasl_server_start.3 sasl_server_step.3 \
		sasl_setprop.3 sasl_usererr.3
MAN8=		sasldblistusers.8 saslpasswd.8

USE_AUTOMAKE=	YES
USE_LIBTOOL=	YES
AUTOHEADER=	autoheader
AUTOMAKE=	automake --add-missing --include-deps

CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc \
		--with-plugindir=${PREFIX}/lib/sasl \
		--with-dbpath=${PREFIX}/etc/sasldb \
		--includedir=${PREFIX}/include/sasl \
		--enable-static \
		--enable-login \
		--with-pwcheck=/var/pwcheck \
		--with-dblib=ndbm \
		--with-rc4=openssl

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		PREFIX="${PREFIX}" \
		TOUCH="${TOUCH}" \
		MKDIR="${MKDIR}" \
		ENABLE_DB3="${ENABLE_DB3}" \
		ENABLE_MYSQL="${ENABLE_MYSQL}" \
		ENABLE_LDAP="${ENABLE_LDAP}"

# ENABLE_* variables can be used by depending ports to enable options.

# JavaSASL needs someone to look at to get it to build
#JAVADIR=	jdk1.1.8
#JAVALIBDIR=	${PREFIX}/${JAVADIR}/lib/i386/green_threads/

#.if defined(USE_JAVA) || exists(${LOCALBASE}/${JAVADIR}/bin/java)
#BUILD_DEPENDS=	${LOCALBASE}/${JAVADIR}/bin/java:${PORTSDIR}/java/jdk
#CONFIGURE_ARGS+=	--with-java \
#			--with-javabase=${LOCALBASE}/include
#
#CONFIGURE_ENV=	JAVAC="${LOCALBASE}/${JAVADIR}/bin/javac" \
#		JAVAH="${LOCALBASE}/${JAVADIR}/bin/javah" \
#		JAVADOC="${LOCALBASE}/${JAVADIR}/bin/javadoc"
#.endif

.if defined(KRB5_HOME) && exists(${KRB5_HOME})
CONFIGURE_ARGS+=	--enable-gssapi=${KRB5_HOME}
.elif defined(HEIMDAL_HOME) && exists(${HEIMDAL_HOME})
CONFIGURE_ARGS+=	--enable-gssapi=${HEIMDAL_HOME}
.else
CONFIGURE_ARGS+=	--disable-gssapi
GSSAPI=	"@comment "
.endif

.if exists(/usr/lib/libkrb.a)
CONFIGURE_ARGS+=	--enable-krb4
.else
CONFIGURE_ARGS+=	--disable-krb4
EBONES=	"@comment "
.endif

CONFIGURE_ENV+=	LOCALBASE=${LOCALBASE} \
		OPENSSLINC=${OPENSSLINC} \
		OPENSSLLIB=${OPENSSLLIB}

DOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README TODO

DOC2=	draft-leach-digest-sasl-05.txt \
	draft-newman-auth-scram-03.txt \
	rfc1321.txt rfc2095.txt rfc2104.txt \
	rfc2222.txt rfc2245.txt

HTDOCS=	gssapi index programming sysadmin

.if defined(NOPORTDOCS)
NODOCS=	"@comment "
.endif

PLIST_SUB=	PREFIX=${PREFIX} \
		GSSAPI=${GSSAPI} \
		EBONES=${EBONES} \
		NOPORTDOCS=${NODOCS}

pre-fetch:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.sasl

pre-configure:
	@(cd ${WRKSRC} && ${AUTOHEADER})

# Create Cyrus user and group
pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${SED} -e "/%%PREFIX%%/s##${PREFIX}#g" ${FILESDIR}/pwcheck.sh \
		> ${PREFIX}/etc/rc.d/pwcheck.sh
	@${CHMOD} 755 ${PREFIX}/etc/rc.d/pwcheck.sh
	${INSTALL} -d -m 770 -o cyrus -g cyrus /var/pwcheck
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/SASL/html
.for file in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/SASL
.endfor
.for file in ${DOC2}
	@${INSTALL_DATA} ${WRKSRC}/doc/${file} ${PREFIX}/share/doc/SASL
.endfor
	@${INSTALL_DATA} ${FILESDIR}/Sendmail.README ${PREFIX}/share/doc/SASL
.for file in ${HTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${file}.html ${PREFIX}/share/doc/SASL/html
.endfor
.endif
	@PKG_PREFIX=${PREFIX} BATCH=${BATCH} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

.include <bsd.port.mk>
