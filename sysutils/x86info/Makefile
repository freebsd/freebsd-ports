# New ports collection makefile for:	x86info
# Date created:				26 Aug 2001
# Whom:					Erik Greenwald <erik@smluc.org>
#
# $FreeBSD$
#

PORTNAME=	x86info
PORTVERSION=	1.30
CATEGORIES=	sysutils
MASTER_SITES=	http://codemonkey.org.uk/projects/x86info/
EXTRACT_SUFX=	.tgz

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	An x86 CPU identification utility

LICENSE=	GPLv2

LIB_DEPENDS=	pci.3:${PORTSDIR}/devel/libpci

ONLY_FOR_ARCHS=	i386 amd64

USE_GMAKE=	yes
ALL_TARGET=	x86info lsmsr
USE_GNOME=	pkgconfig
USE_PYTHON_BUILD=yes
MAKE_JOBS_SAFE=	yes

MAN1=		x86info.1
MAN8=		lsmsr.8
PLIST_FILES=	bin/lsmsr bin/x86info

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 701102
BUILD_DEPENDS+=	${LOCALBASE}/include/cpu.h:${PORTSDIR}/sysutils/devcpu
CFLAGS+=	-I${LOCALBASE}/include
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/x86info ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/lsmsr ${PREFIX}/bin
	${INSTALL_MAN} ${MAN1:S,^,${WRKSRC}/,} ${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${MAN8:S,^,${WRKSRC}/,} ${MAN8PREFIX}/man/man8

.include <bsd.port.post.mk>
