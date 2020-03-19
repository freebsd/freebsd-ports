# Created by: Xin LI <delphij@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sdparm
PORTVERSION=	1.11
CATEGORIES=	sysutils
MASTER_SITES=	http://sg.danny.cz/sg/p/

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Utilities to access SCSI device parameters

LICENSE=	BSD3CLAUSE

BROKEN_FreeBSD_11=	Lack of NVME_STATUS_GET_SCT

USE_LDCONFIG=	yes
USES=		shebangfix tar:tgz
GNU_CONFIGURE=	yes

SHEBANG_FILES=	scripts/sas_disk_blink

PLIST_FILES=	bin/sas_disk_blink \
		bin/sdparm \
		man/man8/sas_disk_blink.8.gz \
		man/man8/sdparm.8.gz

.include <bsd.port.mk>
