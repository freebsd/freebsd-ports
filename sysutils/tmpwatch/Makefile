PORTNAME=	tmpwatch
PORTVERSION=	2.11
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://releases.pagure.org/tmpwatch/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility for removing files based on when they were last accessed
WWW=		https://pagure.io/tmpwatch

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe tar:bzip2
CPE_VENDOR=	redhat

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	sbin/tmpwatch \
		share/man/man8/tmpwatch.8.gz

post-patch:
	@${REINPLACE_CMD} -E "s/^#include.+mntent.h.+//g" ${WRKSRC}/tmpwatch.c

.include <bsd.port.mk>
