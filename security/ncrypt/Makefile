# New ports collection makefile for:	ncrypt
# Date created:			30 Aug 2005
# Whom:				Frank Laszlo <laszlof@vonostingroup.com>
#
# $FreeBSD$
#

PORTNAME=	ncrypt
PORTVERSION=	0.7.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	laszlof@vonostingroup.com
COMMENT=	Advanced AES file encryption tool

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	automake:19 aclocal:19 autoconf:259

PLIST_FILES=	bin/ncrypt bin/nrm

.include <bsd.port.pre.mk>

post-configure:
	@${REINPLACE_CMD} -E 's,^(CC|CFLAGS) =,\1 \?=,g' \
		${WRKSRC}/Makefile
.if (${OSVERSION} < 500000)
	@${REINPLACE_CMD} -e 's,stdint.h,inttypes.h,g' \
		${WRKSRC}/standard.h
	@${REINPLACE_CMD} -e 's,O_SYNC,O_FSYNC,g' \
		${WRKSRC}/wipe_file.c
.endif
.if (${OSVERSION} < 501000)
	@${REINPLACE_CMD} -e 's,ifndef WIN32,if (!defined(__FreeBSD__)),g' \
		${WRKSRC}/ncrypt.c
.endif

.include <bsd.port.post.mk>
