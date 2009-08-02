# New ports collection makefile for:	filelight
# Date created:		Fri Aug 29 21:16:39 CEST 2003
# Whom:			Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$
#

PORTNAME=	filelight
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	sysutils kde
MASTER_SITES=	http://www.methylblue.com/filelight/packages/

MAINTAINER=	decept0@gmail.com
COMMENT=	Represent a file system as a set of concentric segmented-rings

USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool:22
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes

post-patch:
	@${REINPLACE_CMD} -e 's/-O2//g; s/-lpthread/${PTHREAD_LIBS}/g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
