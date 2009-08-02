# New ports collection makefile for:	kdirstat
# Date created:		25 Jun 2002
# Whom:			Stefan Jahn <stefan.jahn@nemesis-sektor.de>
#
# $FreeBSD$
#

PORTNAME=	kdirstat
PORTVERSION=	2.4.4
PORTREVISION=	4
CATEGORIES=	sysutils kde
MASTER_SITES=	http://kdirstat.sourceforge.net/download/

MAINTAINER=	markus@FreeBSD.org
COMMENT=	A small KDE utility that sums up disk usage for directory trees

EXTRA_PATCHES=	${.CURDIR}/../../x11/kde3/files/extrapatch-configure

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
