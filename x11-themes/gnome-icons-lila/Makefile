# New ports collection makefile for:	Gnome iconset Lila
# Date created:				2 Feb 2005
# Whom:					Filippo Natali <filippo@widestore.net>
#
# $FreeBSD$
#

# Port logic gratuitously stolen from x11-themes/kde-icons-noia by
# lioux@.  If it's not defined here and you think it should be, check
# x11-themes/gnome-icons/bsd.gnome-icons.mk for it.

PORTNAME=	lila
PORTVERSION=	0.6.2
CATEGORIES=	x11-themes gnome
MASTER_SITES=	http://lila-theme.uni.cc/files/tarballs/
DISTNAME=	${PORTNAME}-gnome-${PORTVERSION}

MAINTAINER=	filippo.natali@gmail.com
COMMENT=	Lila Icons for Gnome

NO_PACKAGE=	${REASON}
NO_CDROM=	${REASON}
RESTRICTED=	${REASON}

USE_BZIP2=	yes
WRKSRC=		"${WRKDIR}"

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME}-gnome/Lila ${WRKDIR}; \
	${MV} ${WRKDIR}/LICENSE ${WRKSRC}; \
	${MV} ${WRKDIR}/COPYRIGHT ${WRKSRC}

.include "${.CURDIR}/../gnome-icons/bsd.gnome-icons.mk"
.include <bsd.port.mk>
