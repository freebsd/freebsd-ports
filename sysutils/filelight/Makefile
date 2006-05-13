# New ports collection makefile for:	filelight
# Date created:		Fri Aug 29 21:16:39 CEST 2003
# Whom:			Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$
#

PORTNAME=	filelight
PORTVERSION=	0.6.4
PORTREVISION=	4
CATEGORIES=	sysutils kde
MASTER_SITES=	http://www.methylblue.com/filelight/packages/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Represent a file system as a set of concentric segmented-rings

USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes

post-patch:
	@${CP} ${FILESDIR}/mntent* ${WRKSRC}/src
	@${REINPLACE_CMD} -e 's/-O2//g; s/-lpthread/${PTHREAD_LIBS}/g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${RM} ${WRKSRC}/src/settingsdialog.h ${WRKSRC}/src/settingsdialog.cpp

.include <bsd.port.mk>
