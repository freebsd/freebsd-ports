# New ports collection makefile for:   eventwatcher
# Date created:        20 Aug 2004
# Whom:                Lauri Watts <lauri@kde.org>
#
# $FreeBSD$
#

PORTNAME=	eventwatcher
PORTVERSION=	0.4.3
CATEGORIES=	sysutils kde
MASTER_SITES=	SF

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	KDE log file/event viewer

EXTRA_PATCHES=	${.CURDIR}/../../x11/kde3/files/extrapatch-old_configure

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool:15
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=		Does not compile with GCC 4.2
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O2 ||g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
