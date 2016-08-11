# Created by: Denis Barov <dindin@dindin.ru>
# $FreeBSD$

PORTNAME=	sg3_utils
PORTVERSION=	1.42
CATEGORIES=	sysutils
MASTER_SITES=	http://sg.danny.cz/sg/p/

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Set of utilities that send SCSI commands to devices

USES=		gmake libtool shebangfix tar:tgz
SHEBANG_FILES=	scripts/scsi_*

post-install:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsgutils2.so.2

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
