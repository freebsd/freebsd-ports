# New ports collection makefile for: courierimap
# Date created:		19 Feb 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	courier-imap
PORTVERSION=	1.5.3
PORTREVISION=	0
CATEGORIES=	mail ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	courier

MAINTAINER=	nbm@FreeBSD.org

USE_PERL5=	yes
GNU_CONFIGURE=	YES
USE_GMAKE=	YES

#
# options available:
#
# WITHOUT_OPENSSL:		Don't build in TLS support
# WITHOUT_PAM:			Don't build in PAM support
# WITH_VPOPMAIL:		Build in vpopmail support
# WITH_MYSQL:			Build in mysql support
# WITH_POSTGRESQL:		Build in postgresql support
# WITH_LDAP:			Build in ldap support with openldap 2.x
# WITH_LDAP1:			Build in ldap support with openldap 1.x
#

.if !defined(WITHOUT_OPENSSL)
USE_OPENSSL=	YES
PLIST_SUB=	OPENSSLFLAG=
.else
PLIST_SUB=	OPENSSLFLAG="@comment "
.endif

CONFIGURE_ARGS=	--without-authshadow \
		--sysconfdir=${PREFIX}/etc/courier-imap \
		--with-userdb=${PREFIX}/etc/userdb \
		--datadir=${PREFIX}/share/courier-imap \
		--libexecdir=${PREFIX}/libexec/courier-imap \
		--enable-workarounds-for-imap-client-bugs \
		--enable-unicode \
		--disable-root-check

VPOPMAILDIR?=	${LOCALBASE}/vpopmail
.if !defined(WITH_VPOPMAIL)
CONFIGURE_ARGS+=	\
		--without-authvchkpw
.else
CONFIGURE_ARGS+=	\
		--with-authvchkpw
BUILD_DEPENDS+=	${VPOPMAILDIR}/lib/libvpopmail.a:${PORTSDIR}/mail/vpopmail
.endif

.if !defined(WITH_LDAP) && !defined(WITH_LDAP1)
CONFIGURE_ARGS+=	\
		--without-authldap
PLIST_SUB+=	LDAPFLAG="@comment "
.else
CONFIGURE_ARGS+=	\
		--with-authldap
PLIST_SUB+=	LDAPFLAG=""

.if defined(WITH_LDAP)
LIB_DEPENDS=	ldap.2:${PORTSDIR}/net/openldap2 \
		lber.2:${PORTSDIR}/net/openldap2
.else
LIB_DEPENDS=	ldap.1:${PORTSDIR}/net/openldap \
		lber.1:${PORTSDIR}/net/openldap
.endif
.endif

.if !defined(WITH_MYSQL)
CONFIGURE_ARGS+=	\
		--without-authmysql
PLIST_SUB+=	MYSQLFLAG="@comment "
.else
LIB_DEPENDS+=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client
PLIST_SUB+=	MYSQLFLAG=""
.endif

.if !defined(WITH_POSTGRESQL)
CONFIGURE_ARGS+=	\
		--without-authpgsql
PLIST_SUB+=	PGSQLFLAG="@comment "
.else
LIB_DEPENDS+=	pq.2:${PORTSDIR}/databases/postgresql7
PLIST_SUB+=	PGSQLFLAG=""
.endif

.if !defined(WITHOUT_PAM)
CONFIGURE_ARGS+=	\
		--with-authpam
.else
CONFIGURE_ARGS+=	\
		--without-authpam
.endif

.if !defined(WITH_CRAM)
CONFIGURE_ARGS+=	\
		--without-authcram
.else
CONFIGURE_ARGS+=	\
		--with-authcram
.endif

MAN1=		couriertcpd.1 maildirmake.1
MAN7=		authlib.7
MAN8=		makeuserdb.8 userdb.8 userdbpw.8 \
		deliverquota.8 imapd.8 mkimapdcert.8 mkpop3dcert.8

MLINKS=		authlib.7 authpwd.7 \
		authlib.7 authuserdb.7 \
		authlib.7 authshadow.7 \
		authlib.7 authpam.7 \
		authlib.7 authvchkpw.7 \
		authlib.7 authcram.7 \
		authlib.7 authldap.7 \
		authlib.7 authmysql.7 \
		authlib.7 authdaemon.7 \
		authlib.7 authdaemond.7 \
		makeuserdb.8 pw2userdb.8 \
		makeuserdb.8 vchkpw2userdb.8

EXTRA_DOCS=	README INSTALL AUTHORS imap/ChangeLog

.include <bsd.port.pre.mk>

post-patch:
	@${PERL} -i.nbm -pe \
		'm#^\timapd.cnf pop3d.cnf# && s@[ip][mo][ap][p3]d.cnf@@g;' \
		${WRKSRC}/Makefile.in

post-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/authlib/authtest ${PREFIX}/bin/
	@${MKDIR} ${PREFIX}/share/doc/courier-imap
	@${INSTALL_DATA} ${WRKSRC}/imap/imapd.cnf ${PREFIX}/etc/courier-imap/imapd.cnf.dist
	@${INSTALL_DATA} ${WRKSRC}/imap/pop3d.cnf ${PREFIX}/etc/courier-imap/pop3d.cnf.dist
.for a in ${EXTRA_DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${a} ${PREFIX}/share/doc/courier-imap/
.endfor
	ln -s ${PREFIX}/libexec/courier-imap/imapd.rc ${PREFIX}/etc/rc.d/courier-imap-imapd.sh.sample
	ln -s ${PREFIX}/libexec/courier-imap/pop3d.rc ${PREFIX}/etc/rc.d/courier-imap-pop3d.sh.sample
	@echo ""
	@echo "You will have to run ${PREFIX}/share/courier-imap/mkimapdcert to create"
	@echo "a self-signed certificate if you want to use imapd-ssl."
	@echo "And you will have to copy and edit the *.dist files to * in"
	@echo "${PREFIX}/etc/courier-imap ."
	@echo ""

.include <bsd.port.post.mk>
