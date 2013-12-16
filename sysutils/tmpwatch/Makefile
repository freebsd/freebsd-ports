# $FreeBSD$

PORTNAME=	tmpwatch
PORTVERSION=	2.11
CATEGORIES=	sysutils
MASTER_SITES=	https://fedorahosted.org/releases/t/m/tmpwatch/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility for removing files based on when they were last accessed

LICENSE=	GPLv2

USE_BZIP2=	yes

GNU_CONFIGURE=	yes

PLIST_FILES=	sbin/tmpwatch \
		man/man8/tmpwatch.8.gz

post-patch:
	@${REINPLACE_CMD} -E "s/^#include.+mntent.h.+//g" ${WRKSRC}/tmpwatch.c

.include <bsd.port.mk>
