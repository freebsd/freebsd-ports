# $FreeBSD$

PORTNAME=	tmpwatch
PORTVERSION=	2.11
CATEGORIES=	sysutils
MASTER_SITES=	https://releases.pagure.org/tmpwatch/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility for removing files based on when they were last accessed

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe tar:bzip2
CPE_VENDOR=	redhat

GNU_CONFIGURE=	yes

PLIST_FILES=	sbin/tmpwatch \
		man/man8/tmpwatch.8.gz

post-patch:
	@${REINPLACE_CMD} -E "s/^#include.+mntent.h.+//g" ${WRKSRC}/tmpwatch.c

.include <bsd.port.mk>
