# New ports collection makefile for:	tmpwatch
# Date created:			Feb 20, 2002
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	tmpwatch
PORTVERSION=	2.9.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR=	fedora/fedora/1/i386/SRPMS.os
EXTRACT_SUFX=	-2.src.rpm

MAINTAINER=	markp@FreeBSD.org
COMMENT=	A utility for removing files based on when they were last accessed

EXTRACT_DEPENDS=rpm2cpio.pl:${PORTSDIR}/archivers/rpm2cpio

USE_GETOPT_LONG=yes
USE_REINPLACE=	yes

CFLAGS+=	${CPPFLAGS} -DVERSION=\"${PORTVERSION}\"
MAN8=		tmpwatch.8
PLIST_FILES=	sbin/tmpwatch

do-extract:
	${MKDIR} ${WRKDIR}
	cd ${WRKDIR} && \
		${LOCALBASE}/bin/rpm2cpio.pl ${DISTDIR}/${DISTFILES} | \
		${CPIO} -iud
	cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${WRKDIR}/${DISTNAME}.tar.gz ${EXTRACT_AFTER_ARGS}

post-patch:
	${REINPLACE_CMD} -E "s/^#include.+mntent.h.+//g" ${WRKSRC}/tmpwatch.c

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${LDFLAGS} -o tmpwatch tmpwatch.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tmpwatch ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/tmpwatch.8 ${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
