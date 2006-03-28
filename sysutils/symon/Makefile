# New ports collection makefile for:	sysutils/symon
# Date created:				17.02.2005
# Whom:					Ulrich Spoerlein <q@uni.de>
#
# $FreeBSD$
#

PORTNAME=	symon
PORTVERSION=	2.72
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.xs4all.nl/~wpd/symon/philes/

MAINTAINER=	q@galgenberg.net
COMMENT=	Performance and information monitoring tool

WRKSRC=		${WRKDIR}/${PORTNAME}
SUB_FILES=	pkg-message

# Synonym for WITHOUT_SYMUX
.if defined(WITHOUT_RRD)
WITHOUT_SYMUX=	yes
.endif

.if !defined(WITHOUT_SYMUX)
LIB_DEPENDS+=	rrd.2:${PORTSDIR}/net/rrdtool
.endif

.if defined(WITHOUT_SYMUX) && defined(WITHOUT_SYMON)
IGNORE=	you have defined both WITHOUT_SYMUX or WITHOUT_RRD *and* WITHOUT_SYMON
.endif

SUBDIR=		lib
.if !defined(WITHOUT_SYMON)
SUBDIR+=	symon
MAN8+=		symon.8
PLIST_SUB+=	SYMON=""
USE_RC_SUBR+=	symon.sh
.else
PLIST_SUB+=	SYMON="@comment "
.endif
.if !defined(WITHOUT_SYMUX)
SUBDIR+=	symux
MAN8+=		symux.8
PLIST_SUB+=	SYMUX=""
USE_RC_SUBR+=	symux.sh
.else
PLIST_SUB+=	SYMUX="@comment "
.endif
SUBDIR+=	client

MAKE_ARGS+=	SUBDIR="${SUBDIR}" RRDDIR="${LOCALBASE}"

.include <bsd.port.pre.mk>

# Symux doesn't need additional LIBS. Symon doesn't need libkvm on FreeBSD 4.x
post-patch:
	@${REINPLACE_CMD} 's/^LIBS+=/LIBS=/' ${WRKSRC}/symux/Makefile
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} 's/-lkvm//' ${WRKSRC}/platform/FreeBSD/Makefile.inc
.endif

pre-install:
	@${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
