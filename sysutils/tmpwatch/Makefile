# New ports collection makefile for:	tmpwatch
# Date created:			Feb 20, 2002
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	tmpwatch
PORTVERSION=	2.8.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_REDHAT_LINUX}
MASTER_SITE_SUBDIR=	updates/7.2/en/os/SRPMS
EXTRACT_SUFX=	-1.src.rpm

MAINTAINER=	markp@FreeBSD.org

BUILD_DEPENDS=	rpm2cpio:${PORTSDIR}/archivers/rpm2cpio
LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

CPIO?=		/usr/bin/cpio
CFLAGS+=	-I${LOCALBASE}/include -DVERSION=\"${PORTVERSION}\"
LDFLAGS+=	-L${LOCALBASE}/lib -lgnugetopt
MAN8=		tmpwatch.8

do-extract:
	${MKDIR} ${WRKDIR}
	cd ${WRKDIR} && \
		${LOCALBASE}/bin/rpm2cpio ${DISTDIR}/${DISTFILES} | \
		${CPIO} -iud
	cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${WRKDIR}/${DISTNAME}.tar.gz ${EXTRACT_AFTER_ARGS}

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${LDFLAGS} -o tmpwatch tmpwatch.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tmpwatch ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/tmpwatch.8 ${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
