# New ports collection makefile for:	maildrop
# Date created:		16 November 1998
# Whom:			Tom Hukins <tom@eborcom.com>
#
# $FreeBSD$
#

# The following compile-time options are available:
# WITH_GDBM=yes		Enable database extensions using GDBM (default: off)
# WITH_USERDB=yes	Enable optional userdb authentication
# WITH_MAILDIRQUOTA=yes Enable optional support for maildir quotas
# MAILDROP_SUID=<uid>,
# MAILDROP_SGID=<gid>	Maildrop will be installed with suid permissions for
#			MAILDROP_SUID, and sgid permissions for MAILDROP_SGID.
#			If undefined, these values default to "root" and "mail"
#			respectively, which should be suitable for most systems.
# NO_MAILWRAPPER=yes	If defined, let configure guess which sendmail binary
#			to use
# WITH_LDAP=yes		Enable experimental virtual user LDAP support
# WITH_MYSQL=yes	Enable experimental virtual user MySQL support

PORTNAME=	maildrop
PORTVERSION=	1.6.3
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	courier

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Mail delivery agent (MDA) with filtering abilities

USE_BZIP2=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--enable-syslog=1 \
		--enable-use-flock \
		--with-etcdir="${PREFIX}/etc" \
		--enable-maildrop-uid="${MAILDROP_SUID}" \
		--enable-maildrop-gid="${MAILDROP_SGID}"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if defined(WITH_GDBM)
LIB_DEPENDS+=		gdbm.3:${PORTSDIR}/databases/gdb
CONFIGURE_ARGS+=	--with-db=gdbm
.else
CONFIGURE_ARGS+=	--without-db
.endif

.if defined(WITH_USERDB)
CONFIGURE_ARGS+=	--enable-userdb
MAN1=		makedat.1
MAN8=		makeuserdb.8 userdb.8 userdbpw.8
MLINKS+=	makeuserdb.8 pw2userdb.8 \
		makeuserdb.8 vchkpw2userdb.8
EXTRA_TARGET+=	install-userdb install-makedat
PLIST_SUB+=	USERDB=""
.else
PLIST_SUB+=	USERDB="@comment "
.endif

.if defined(WITH_MAILDIRQUOTA)
CONFIGURE_ARGS+=	--enable-maildirquota
EXTRA_TARGET+=	install-deliverquota
PLIST_SUB+=	MAILDIRQUOTA=""
.else
PLIST_SUB+=	MAILDIRQUOTA="@comment "
.endif

.if !defined(NO_MAILWRAPPER)
CONFIGURE_ARGS+=	--enable-sendmail=/usr/sbin/sendmail
.endif

.if exists(${LOCALBASE}/lib/libfam.so.0)
LIB_DEPENDS+=	fam.0:${PORTSDIR}/devel/fam
.endif

.if defined(WITH_LDAP)
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=	--enable-maildropldap \
			--with-ldapconfig=${PREFIX}/etc/maildropldap.config
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--enable-maildropmysql \
			--with-mysqlconfig=${PREFIX}/etc/maildropmysql.config
LDFLAGS+=		-L${LOCALBASE}/lib/mysql
.endif

MAILDROP_SUID?=	root
MAILDROP_SGID?=	mail

.if defined(NOPORTDOCS)
# Just install the binary and man pages, no extra documentation
INSTALL_TARGET=	install-maildrop install-man ${EXTRA_TARGET}
.else
INSTALL_TARGET=	install-strip
.endif

MAN1+=	lockmail.1 mailbot.1 maildirmake.1 maildrop.1 makemime.1 \
	reformail.1 reformime.1
MAN5=	maildir.5 maildropex.5 maildropfilter.5 maildropgdbm.5
MAN7=	maildirquota.7
MAN8+=	deliverquota.8
DOCS=	AUTHORS INSTALL INSTALL.html README README.html README.postfix \
	UPGRADE UPGRADE.html maildroptips.txt maildir/README.*

.if !defined(NOPORTDOCS)
post-install:
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
