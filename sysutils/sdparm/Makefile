PORTNAME=	sdparm
PORTVERSION=	1.12
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://sg.danny.cz/sg/p/

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Utilities to access SCSI device parameters
WWW=		https://sg.danny.cz/sg/sdparm.html

LICENSE=	BSD3CLAUSE

USE_LDCONFIG=	yes
USES=		shebangfix tar:tgz
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

SHEBANG_FILES=	scripts/sas_disk_blink

PLIST_FILES=	bin/sas_disk_blink \
		bin/sdparm \
		share/man/man8/sas_disk_blink.8.gz \
		share/man/man8/sdparm.8.gz

.include <bsd.port.mk>
