# New ports collection makefile for:	maildrop
# Date created:		16 November 1998
# Whom:			Tom Hukins <tom@eborcom.com>
#
# $FreeBSD$
#

# The following compile-time options are available:
# WITH_GDBM=yes		Enable database extensions using GDBM (default: off)
# MAILDROP_SUID=<uid>,
# MAILDROP_SGID=<gid>	Maildrop will be installed with suid permissions for
#			MAILDROP_SUID, and sgid permissions for MAILDROP_SGID.
#			If undefined, these values default to "root" and "mail"
#			respectively, which should be suitable for most systems.
# MAILDROP_TRUSTED_USERS=<user> Specify users allowed to use the -d option
# NO_MAILWRAPPER=yes	If defined, let configure guess which sendmail binary
#			to use
# WITH_AUTHLIB=yes	Enable optional support for Courier Auth Library

PORTNAME=	maildrop
PORTVERSION=	1.8.0
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
		--enable-use-flock=1 \
		--with-etcdir="${PREFIX}/etc" \
		--enable-maildrop-uid="${MAILDROP_SUID}" \
		--enable-maildrop-gid="${MAILDROP_SGID}" \
		--enable-maildirquota
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 502010
USE_GMAKE	=yes
.endif

.if defined(WITH_GDBM)
LIB_DEPENDS+=		gdbm.3:${PORTSDIR}/databases/gdbm
CONFIGURE_ARGS+=	--with-db=gdbm
.else
CONFIGURE_ARGS+=	--without-db
.endif

.if !defined(NO_MAILWRAPPER)
CONFIGURE_ARGS+=	--enable-sendmail=/usr/sbin/sendmail
.endif

.if exists(${LOCALBASE}/lib/libfam.so.0)
LIB_DEPENDS+=	fam.0:${PORTSDIR}/devel/fam
.endif

.if defined(MAILDROP_TRUSTED_USERS)
CONFIGURE_ARGS+=	--enable-trusted-users="${MAILDROP_TRUSTED_USERS}"
.endif

.if defined(WITH_AUTHLIB)
BUILD_DEPENDS=	${LOCALBASE}/bin/courierauthconfig:${PORTSDIR}/mail/courier-authlib
RUN_DEPENDS=	${LOCALBASE}/bin/courierauthconfig:${PORTSDIR}/mail/courier-authlib
LDFLAGS+=	-L${LOCALBASE}/lib/courier-authlib -rpath ${LOCALBASE}/lib/courier-authlib
.else
CONFIGURE_ARGS+=	--disable-authlib
.endif

MAILDROP_SUID?=	root
MAILDROP_SGID?=	mail

.if defined(NOPORTDOCS)
# Just install the binary and man pages, no extra documentation
INSTALL_TARGET=	install-maildrop install-deliverquota install-man
.else
INSTALL_TARGET=	install-strip
.endif

MAN1+=	lockmail.1 mailbot.1 maildirmake.1 maildrop.1 makemime.1 \
	reformail.1 reformime.1
MAN5=	maildir.5
MAN7=	maildirquota.7 maildropex.7 maildropfilter.7 maildropgdbm.7
MAN8+=	deliverquota.8
DOCS=	AUTHORS INSTALL INSTALL.html README README.html README.postfix \
	UPGRADE UPGRADE.html maildroptips.txt maildir/README.*

.if !defined(NOPORTDOCS)
post-install:
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
