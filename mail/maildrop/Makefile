# New ports collection makefile for:	maildrop
# Date created:		16 November 1998
# Whom:			Tom Hukins <tom@eborcom.com>
#
# $FreeBSD$
#

PORTNAME=	maildrop
PORTVERSION= 	0.64
CATEGORIES=	mail
MASTER_SITES=	http://www.flounder.net/~mrsam/maildrop/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR= system/mail/mailhandlers

MAINTAINER=	tom@eborcom.com

# Maildrop is usually installed with gdbm extensions. If you do not
# want these extensions installed, NO_GDBM must be defined.
#
.if !defined(NO_GDBM)
BUILD_DEPENDS=	${LOCALBASE}/lib/libgdbm.a:${PORTSDIR}/databases/gdbm
.endif

ALL_TARGET=	config.h xconfig.h all
INSTALL_TARGET=	install-strip

# Maildrop will be installed with suid permissions for MAILDROP_SUID,
# and sgid permissions for MAILDROP_SGID. If undefined, these values
# default to "root" and "mail" respectively, which should be suitable
# for most systems.
#
MAILDROP_SUID?=	root
MAILDROP_SGIG?=	mail

CONFIGURE_ARGS=	--enable-syslog=1 \
		--with-docdir="${PREFIX}/share/doc/maildrop" \
		--with-etcdir="${PREFIX}/etc" \
		--enable-maildrop-uid="${MAILDROP_SUID}" \
		--enable-maildrop-gid="${MAILDROP_SGID}"
CONFIGURE_ENV=	CPPFLAGS="-I${PREFIX}/include" \
		LIBS="-L${PREFIX}/lib"
GNU_CONFIGURE=	yes

.if defined(NOPORTDOCS)
INSTALL_TARGET=	install-exec all
.else
MAN1=		dotlock.1 maildrop.1 maildrop.makegdbm.1 reformail.1 reformime.1
MAN5=		maildropex.5 maildropfilter.5 maildropgdbm.5
MANCOMPRESSED=	yes
.endif

.if defined(NO_GDBM)
CONFIGURE_ARGS+=	--without-gdbm
.endif

PLIST=	${WRKDIR}/PLIST

post-patch:
	@${CP} ${PKGDIR}/PLIST ${WRKDIR}
.if !defined(NO_GDBM)
	@${CAT} ${PKGDIR}/PLIST.gdbm >> ${WRKDIR}/PLIST
.endif
.if !defined(NOPORTDOCS)
	@${CAT} ${PKGDIR}/PLIST.docs >> ${WRKDIR}/PLIST
.endif

.include <bsd.port.mk>
