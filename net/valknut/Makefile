# New ports collection makefile for:    dclib
# Date created:                         Wed 10 Jul 2002
# Whom:	Sverrir Valgeirsson <e96sv@yahoo.se> and
#	Amar Takhar <verm@drunkmonk.net> et al
#
# $FreeBSD$
#

PORTNAME=	dcgui
PORTVERSION=	0.2.20
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://download.berlios.de/dcgui/
DISTNAME=	dcgui-qt-${PORTVERSION}

MAINTAINER=	brueffer@phoenix-systems.de
COMMENT=	A Direct Connect client QT GUI

LIB_DEPENDS=	dc.0:${PORTSDIR}/net/dclib \
		xml2.5:${PORTSDIR}/textproc/libxml2

USE_X_PREFIX=	yes
USE_QT_VER=	3
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libdc=${LOCALBASE}

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

post-patch:
	@${REINPLACE_CMD} -e 's/-O2//g; s/-lpthread/${PTHREAD_LIBS}/g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
