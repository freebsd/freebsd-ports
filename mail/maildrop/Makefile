# New ports collection makefile for:	maildrop
# Date created:		16 November 1998
# Whom:			Tom Hukins <tom@eborcom.com>
#
# $FreeBSD$
#

# The following compile-time options are available:
# WITH_AUTHLIB=yes	Enable optional support for Courier Auth Library
# WITH_FAM=yes		Enable optional support for File Alteration Monitor
# WITH_GDBM=yes		Enable database extensions using GDBM (default: off)
# MAILDROP_SUID=<uid>,
# MAILDROP_SGID=<gid>	Maildrop will be installed with suid permissions for
#			MAILDROP_SUID, and sgid permissions for MAILDROP_SGID.
# MAILDROP_TRUSTED_USERS=<user> Specify users allowed to use the -d option
# NO_MAILWRAPPER=yes	If defined, let configure guess which sendmail binary
#			to use

PORTNAME=	maildrop
PORTVERSION=	2.0.2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	courier

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Mail delivery agent (MDA) with filtering abilities

USE_GPG=	yes
SIG_SUFFIX=	.sig
USE_BZIP2=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--enable-syslog=1 \
		--enable-use-flock=1 \
		--with-etcdir="${PREFIX}/etc" \
		--enable-maildirquota
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre

.if defined(WITH_AUTHLIB)
.if exists(${.CURDIR}/../../security/courier-authlib/Makefile.opt)
.include "${.CURDIR}/../../security/courier-authlib/Makefile.opt"
.endif
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 502010
USE_GMAKE	=yes
.endif

.if defined(WITH_GDBM)
LIB_DEPENDS+=		gdbm.3:${PORTSDIR}/databases/gdbm
CONFIGURE_ARGS+=	--with-db=gdbm
.else
CONFIGURE_ARGS+=	--without-db
.endif

.if defined(MAILDROP_SUID)
CONFIGURE_ARGS+=	--enable-maildrop-uid="${MAILDROP_SUID}"
.endif

.if defined(MAILDROP_SGID)
CONFIGURE_ARGS+=	--enable-maildrop-gid="${MAILDROP_SGID}"
.endif

.if !defined(NO_MAILWRAPPER)
CONFIGURE_ARGS+=	--enable-sendmail=/usr/sbin/sendmail
.endif

.if defined(WITH_FAM) || exists(${LOCALBASE}/lib/libfam.so.0)
USE_FAM=	yes
.endif

.if defined(MAILDROP_TRUSTED_USERS)
CONFIGURE_ARGS+=	--enable-trusted-users="${MAILDROP_TRUSTED_USERS}"
.endif

.if defined(WITH_AUTHLIB)
.if exists(${.CURDIR}/../../security/courier-authlib/Makefile.dep)
.include "${.CURDIR}/../../security/courier-authlib/Makefile.dep"
.endif
BUILD_DEPENDS+=	courierauthconfig:${PORTSDIR}/security/courier-authlib-base
RUN_DEPENDS+=	courierauthconfig:${PORTSDIR}/security/courier-authlib-base
CONFIGURE_ARGS+=	--enable-authlib

post-patch:
	@${REINPLACE_CMD} -e 's|@LIBS@|@LIBS@ \
		-rpath=:${LOCALBASE}/lib/courier-authlib|' \
		${WRKSRC}/maildrop/Makefile.in
.else
CONFIGURE_ARGS+=	--disable-authlib
.endif

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

post-install:
	${INSTALL_DATA} ${WRKSRC}/maildir/quotawarnmsg \
		${PREFIX}/etc/quotawarnmsg.sample
.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
.if defined(MAILDROP_SUID)
	${CHMOD} u+s ${PREFIX}/bin/maildrop
.endif
.if defined(MAILDROP_SGID)
	${CHMOD} g+s ${PREFIX}/bin/maildrop
.endif

.include <bsd.port.post.mk>
