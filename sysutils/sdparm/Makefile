# Created by: Xin LI <delphij@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sdparm
PORTVERSION=	1.08
CATEGORIES=	sysutils
MASTER_SITES=	http://sg.danny.cz/sg/p/
EXTRACT_SUFX=	.tgz

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Utilities to access SCSI device parameters

USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

MAN8=		sas_disk_blink.8 \
		sdparm.8

PLIST_FILES=	bin/sas_disk_blink \
		bin/sdparm

NO_STAGE=	yes
.include <bsd.port.mk>
