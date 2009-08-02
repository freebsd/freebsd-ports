# New ports collection makefile for:	baghira
# Date created:			31 August 2004
# Whom:		 		Miguel Mendez <flynn@energyhq.es.eu.org>
#
# $FreeBSD$
#

PORTNAME=	baghira
PORTVERSION=	0.8
PORTREVISION=	4
CATEGORIES=	x11-themes kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Aqua like window decoration and widget style for KDE

#WRKSRC=		${WRKDIR}/${PORTNAME}-release

#EXTRA_PATCHES=	${.CURDIR}/../../x11/kde3/files/extrapatch-configure

USE_BZIP2=	yes
USE_KDEBASE_VER=3
USE_XORG=	xtst
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22

# XXX - Workaround for a badly rolled tarball.
#pre-configure:
#	@${REINPLACE_CMD} -e 's|rm -f configure|true|g' ${WRKSRC}/Makefile.in \
#						${WRKSRC}/admin/am_edit

.include <bsd.port.mk>
