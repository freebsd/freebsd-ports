# New ports collection makefile for:	maildrop
# Date created:		16 November 1998
# Whom:			Tom Hukins <tom@eborcom.com>
#
# $FreeBSD$
#

PORTNAME=	maildrop
PORTVERSION=	1.5.0
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	courier

MAINTAINER=	petef@FreeBSD.org

# Maildrop is usually installed with gdbm extensions. If you do not
# want these extensions installed, define WITHOUT_GDBM.
#
.if !defined(WITHOUT_GDBM)
LIB_DEPENDS=	gdbm.3:${PORTSDIR}/databases/gdbm
.endif

INSTALL_TARGET=	install-strip

# Maildrop will be installed with suid permissions for MAILDROP_SUID,
# and sgid permissions for MAILDROP_SGID. If undefined, these values
# default to "root" and "mail" respectively, which should be suitable
# for most systems.
#
MAILDROP_SUID?=	root
MAILDROP_SGID?=	mail

CONFIGURE_ARGS+=	--enable-syslog=1 \
		--enable-use-flock \
		--with-etcdir="${PREFIX}/etc" \
		--enable-maildrop-uid="${MAILDROP_SUID}" \
		--enable-maildrop-gid="${MAILDROP_SGID}"
.if defined(MAILDROPDEFAULT)
CONFIGURE_ARGS+=	--with-default-maildrop=${MAILDROPDEFAULT}
.endif
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${CPPFLAGS}" \
		LIBS="-L${LOCALBASE}/lib"
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_PERL5_BUILD=yes
USE_PERL5_RUN=	yes

.if defined(NOPORTDOCS)
# Just install the binary and man pages, no extra documentation
INSTALL_TARGET=	install-maildrop install-man
.endif

MAN1=		lockmail.1 mailbot.1 maildirmake.1 maildrop.1 makemime.1 \
		reformail.1 reformime.1
MAN5=		maildropex.5 maildropfilter.5 maildropgdbm.5
MAN7=		maildirquota.7
MAN8=		deliverquota.8

.if defined(WITHOUT_GDBM)
CONFIGURE_ARGS+=	--without-db
.endif

.include <bsd.port.mk>
