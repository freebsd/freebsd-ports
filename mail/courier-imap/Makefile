# New ports collection makefile for: courierimap
# Date created:		19 Feb 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	courier-imap
PORTVERSION=	1.3.12
PORTREVISION=	0
CATEGORIES=	mail ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	courier

MAINTAINER=	nbm@FreeBSD.org

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
#

.if !defined(WITHOUT_OPENSSL)
USE_OPENSSL=	YES
PLIST_SUB=	OPENSSLFLAG=
.else
PLIST_SUB=	OPENSSLFLAG="@comment "
.endif

CONFIGURE_ARGS=	--without-authldap --with-authldaprc=filename \
		--without-authshadow \
		--without-authcram \
		--sysconfdir=${PREFIX}/etc/courier-imap \
		--with-userdb=${PREFIX}/etc/userdb \
		--datadir=${PREFIX}/share/courier-imap \
		--libexecdir=${PREFIX}/libexec/courier-imap \
		--enable-workarounds-for-imap-client-bugs \
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

MAN1=		maildirmake.1
MAN8=		authlib.8 makeuserdb.8 userdb.8 userdbpw.8 couriertcpd.8 \
		deliverquota.8 imapd.8 mkimapdcert.8 mkpop3dcert.8

MLINKS=		authlib.8 authpwd.8 \
		authlib.8 authuserdb.8 \
		authlib.8 authshadow.8 \
		authlib.8 authpam.8 \
		authlib.8 authvchkpw.8 \
		authlib.8 authcram.8 \
		authlib.8 authldap.8 \
		authlib.8 authmysql.8 \
		authlib.8 authdaemon.8 \
		authlib.8 authdaemond.8 \
		makeuserdb.8 pw2userdb.8 \
		makeuserdb.8 vchkpw2userdb.8

EXTRA_DOCS=	README INSTALL AUTHORS imap/ChangeLog

.include <bsd.port.pre.mk>

post-patch:
	@perl -i.nbm -pe 'm#^\timapd.cnf pop3d.cnf# && s@[ip][mo][ap][p3]d.cnf@@g;' \
		${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${PREFIX}/share/doc/courier-imap
	@${INSTALL_DATA} ${WRKSRC}/imap/imapd.cnf ${PREFIX}/etc/courier-imap/imapd.cnf.dist
	@${INSTALL_DATA} ${WRKSRC}/imap/pop3d.cnf ${PREFIX}/etc/courier-imap/pop3d.cnf.dist
.for a in ${EXTRA_DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${a} ${PREFIX}/share/doc/courier-imap/
.endfor

.include <bsd.port.post.mk>
