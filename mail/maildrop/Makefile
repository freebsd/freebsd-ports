# New ports collection makefile for:	maildrop
# Version required:	0.60
# Date created:		16 November 1998
# Whom:			Tom Hukins <tom@eborcom.com>
#
# $Id$
#

DISTNAME=	maildrop-0.60
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR= system/mail/mailhandlers

MAINTAINER=	tom@eborcom.com

ALL_TARGET=	autoconf.h config.h all

# Maildrop will be installed with suid permissions for MAILDROP_SUID,
# and sgid permissions for MAILDROP_SGID. If undefined, these values
# default to "root" and "mail" respectively, which should be suitable
# for most systems.
#
.if !defined(MAILDROP_SUID)
MAILDROP_SUID=	root
.endif
.if !defined(MAILDROP_SGID)
MAILDROP_SGID=	mail
.endif

CONFIGURE_ARGS=	--enable-syslog=1 \
		--enable-maildrop-uid="${MAILDROP_SUID}" \
		--enable-maildrop-gid="${MAILDROP_SGID}"
CONFIGURE_ENV+=	CXX="${CXX}" \
		CXXFLAGS="${CXXFLAGS}"
GNU_CONFIGURE=	yes

.if defined(NOPORTDOCS)
PLIST=		${PKGDIR}/PLIST.nodocs
INSTALL_TARGET=	install-exec all
.else
MAN1=		dotlock.1 maildrop.1 reformail.1
MAN5=		maildropex.5 maildropfilter.5
MANCOMPRESSED=	yes
.endif

post-patch:
.for file in README.html maildrop.1 maildrop.html maildropfilter.5 maildropfilter.html main.C recipenode.C
	@${MV} ${WRKSRC}/${file} ${WRKSRC}/${file}.bak
	@${SED} < ${WRKSRC}/${file}.bak > ${WRKSRC}/${file} s+!!PREFIX!!+${PREFIX}+g
.endfor

.include <bsd.port.mk>
