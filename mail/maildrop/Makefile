# New ports collection makefile for:	maildrop
# Date created:		16 November 1998
# Whom:			Tom Hukins <tom@eborcom.com>
#
# $FreeBSD$
#

# The following compile-time options are available:
# WITHOUT_GDBM=yes	Disable building maildrop gdbm extensions.
#			(default: enabled)
# WITH_MAILDIRQUOTA=yes Enable optional support for maildir quotas
#			(default: disabled)
# MAILDROP_SUID=<uid>,
# MAILDROP_SGID=<gid>	Maildrop will be installed with suid permissions for
#			MAILDROP_SUID, and sgid permissions for MAILDROP_SGID.
#			If undefined, these values default to "root" and "mail"
#			respectively, which should be suitable for most
#			systems.
# NO_MAILWRAPPER	If defined, let configure guess which sendmail binary
#			to use

PORTNAME=	maildrop
PORTVERSION=	1.5.2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	courier

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Replacement local mail delivery agent, similar to procmail

.if !defined(WITHOUT_GDBM)
LIB_DEPENDS=	gdbm.3:${PORTSDIR}/databases/gdbm
.else
CONFIGURE_ARGS+=	--without-db
.endif

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_PERL5_BUILD=yes
USE_PERL5_RUN=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${CPPFLAGS}" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--enable-syslog=1 \
		--enable-use-flock \
		--with-etcdir="${PREFIX}/etc" \
		--enable-maildrop-uid="${MAILDROP_SUID}" \
		--enable-maildrop-gid="${MAILDROP_SGID}"

.if !defined(NO_MAILWRAPPER)
CONFIGURE_ARGS+=	--enable-sendmail=/usr/sbin/sendmail
.endif

.if defined(WITH_MAILDIRQUOTA)
CONFIGURE_ARGS+=	--enable-maildirquota
PLIST_SUB+=	MAILDIRQUOTA=""
.else
PLIST_SUB+=	MAILDIRQUOTA="@comment "
.endif

MAILDROP_SUID?=	root
MAILDROP_SGID?=	mail

.if !defined(NOPORTDOCS)
INSTALL_TARGET=	install-strip
.else
# Just install the binary and man pages, no extra documentation
INSTALL_TARGET=	install-maildrop install-man
.endif

MAN1=		lockmail.1 mailbot.1 maildirmake.1 maildrop.1 makemime.1 \
		reformail.1 reformime.1
MAN5=		maildir.5 maildropex.5 maildropfilter.5 maildropgdbm.5
MAN7=		maildirquota.7
MAN8=		deliverquota.8
DOCS=		INSTALL INSTALL.html README README.html README.postfix \
		UPGRADE UPGRADE.html maildroptips.txt \
		maildir/README.*.html maildir/README.*.txt

.if !defined(NOPORTDOCS)
post-install:
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
