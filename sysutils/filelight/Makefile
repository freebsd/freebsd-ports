# Created by: Markus Brueffer <brueffer@phoenix-systems.de>
# $FreeBSD$

PORTNAME=	filelight
PORTVERSION=	1.0
PORTREVISION=	7
CATEGORIES=	sysutils kde
MASTER_SITES=	http://www.methylblue.com/filelight/packages/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Represent a file system as a set of concentric segmented-rings

USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes

post-patch:
	@${REINPLACE_CMD} -e 's/-O2//g; s/-lpthread/${PTHREAD_LIBS}/g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
