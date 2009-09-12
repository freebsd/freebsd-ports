# New ports collection makefile for:	sysutils/symon
# Date created:				17.02.2005
# Whom:					Ulrich Spoerlein <uspoerlein@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	symon
PORTVERSION=	2.79
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.xs4all.nl/~wpd/symon/philes/

MAINTAINER=	uqs@spoerlein.net
COMMENT=	Performance and information monitoring tool

WRKSRC=		${WRKDIR}/${PORTNAME}
SUB_FILES=	pkg-message

USE_PERL5_BUILD=	yes

# Synonym for WITHOUT_SYMUX
.if defined(WITHOUT_RRD)
WITHOUT_SYMUX=	yes
.endif

.if !defined(WITHOUT_SYMUX)
LIB_DEPENDS+=	rrd:${PORTSDIR}/databases/rrdtool
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

# Symux doesn't need additional LIBS.
post-patch:
	@${REINPLACE_CMD} 's/^LIBS+=/LIBS=/' ${WRKSRC}/symux/Makefile

pre-install:
	@${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
