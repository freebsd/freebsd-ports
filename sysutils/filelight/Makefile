# New ports collection makefile for:	filelight
# Date created:		Fri Aug 29 21:16:39 CEST 2003
# Whom:			Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$
#

PORTNAME=	filelight
PORTVERSION=	0.6.4
PORTREVISION=	1
CATEGORIES=	sysutils kde
MASTER_SITES=	http://www.methylblue.com/filelight/

MAINTAINER=	brueffer@phoenix-systems.de
COMMENT=	Represent a file system as a set of concentric segmented-rings

USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

post-patch:
	@${CP} ${FILESDIR}/mntent* ${WRKSRC}/src
	@${REINPLACE_CMD} -e 's/-O2//g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
