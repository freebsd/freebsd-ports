# Created by: Denis Barov <dindin@dindin.ru>
# $FreeBSD$

PORTNAME=	sg3_utils
DISTVERSION=	1.45
CATEGORIES=	sysutils
MASTER_SITES=	http://sg.danny.cz/sg/p/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of utilities that send SCSI commands to devices

LICENSE=	BSD2CLAUSE GPLv2+
LICENSE_COMB=	multi
LICENSE_FILE_BSD2CLAUSE=	${WRKSRC}/BSD_LICENSE
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING

USES=		gmake libtool shebangfix tar:tgz
USE_LDCONFIG=	yes
SHEBANG_FILES=	scripts/*

GNU_CONFIGURE=	yes

post-install:
		@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsgutils2*.so.*

.include <bsd.port.mk>
