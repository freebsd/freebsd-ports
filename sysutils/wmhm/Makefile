# New ports collection makefile for:   wmhm
# Date created:        21 September 1999
# Whom:                Mike Muir <mmuir@es.co.nz>
#
# $FreeBSD$
#

PORTNAME=	wmhm
PORTVERSION=	1.46
PORTREVISION=	3
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	fenner

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WindowMaker dockable hardware monitor for FreeBSD

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

WRKSRC=		${WRKDIR}/wmhm/wmhm

GNU_CONFIGURE=	yes
MAN8=		wmhm.8
MANCOMPRESSED=	yes
PLIST_FILES=	bin/wmhm
USE_XORG=	xpm
ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	"requires speaker(4)"
ALL_TARGET=	-j`${SYSCTL} -n hw.ncpu`

CONFIGURE_ARGS+=--with-xpm-includes=${LOCALBASE}/include \
		--with-xpm-library=${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if (${OSVERSION} < 601000) && (${ARCH} == "amd64")
IGNORE=		5.x does not support speaker(4)
.endif

post-install:
	${STRIP_CMD} ${PREFIX}/bin/wmhm

.include <bsd.port.post.mk>
