# New ports collection makefile for:	maildrop
# Date created:		16 November 1998
# Whom:			Tom Hukins <tom@eborcom.com>
#
# $FreeBSD$
#

PORTNAME=	maildrop
PORTVERSION=	1.3.0
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR= courier

MAINTAINER=	tom@FreeBSD.org

# Maildrop is usually installed with gdbm extensions. If you do not
# want these extensions installed, NO_GDBM must be defined.
#
.if !defined(NO_GDBM)
BUILD_DEPENDS=	${LOCALBASE}/lib/libgdbm.a:${PORTSDIR}/databases/gdbm
.endif

ALL_TARGET=	all
INSTALL_TARGET=	install-strip

# Maildrop will be installed with suid permissions for MAILDROP_SUID,
# and sgid permissions for MAILDROP_SGID. If undefined, these values
# default to "root" and "mail" respectively, which should be suitable
# for most systems.
#
MAILDROP_SUID?=	root
MAILDROP_SGID?=	mail

CONFIGURE_ARGS=	--enable-syslog=1 \
		--with-docdir="${PREFIX}/share/doc/maildrop" \
		--with-etcdir="${PREFIX}/etc" \
		--enable-maildrop-uid="${MAILDROP_SUID}" \
		--enable-maildrop-gid="${MAILDROP_SGID}"
CONFIGURE_ENV=	CPPFLAGS="-I${PREFIX}/include" \
		LIBS="-L${PREFIX}/lib"
GNU_CONFIGURE=	yes

.if defined(NOPORTDOCS)
INSTALL_TARGET=	install-maildrop install-man
.else
MAN1=		dotlock.1 maildirmake.1 maildrop.1 makemime.1 reformail.1 reformime.1
MAN5=		maildropex.5 maildropfilter.5 maildropgdbm.5
MAN8=		maildirquota.8 deliverquota.8
.endif

.if defined(NO_GDBM)
CONFIGURE_ARGS+=	--without-db
.endif

.include <bsd.port.mk>
