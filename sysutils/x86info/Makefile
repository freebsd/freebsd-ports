# New ports collection makefile for:	x86info
# Date created:			26 Aug 2001
# Whom:				Erik Greenwald <erik@smluc.org>
#
# $FreeBSD$
#

PORTNAME=	x86info
PORTVERSION=	1.29
PORTREVISION=	0
CATEGORIES=	sysutils
MASTER_SITES=	http://codemonkey.org.uk/projects/x86info/ \
		http://codemonkey.org.uk/projects/x86info/old/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to display information about the systems x86 processor(s)

LIB_DEPENDS=	pci.3:${PORTSDIR}/devel/libpci

USE_GMAKE=	yes
USE_PYTHON_BUILD=	yes
USE_GNOME=	pkgconfig
LICENSE=	GPLv2
ALL_TARGET=	x86info lsmsr
ONLY_FOR_ARCHS=	i386 amd64
PLIST_FILES=	bin/x86info bin/lsmsr
MAKE_JOBS_SAFE=	yes
MAN1=	x86info.1
MAN8=	lsmsr.8

post-patch:
	${REINPLACE_CMD} -E -e 's,-g -O2,${CFLAGS},g' ${WRKSRC}/Makefile

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 701102
BUILD_DEPENDS+=	${LOCALBASE}/include/cpu.h:${PORTSDIR}/sysutils/devcpu
CFLAGS+=	-I"${LOCALBASE}"/include
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/x86info ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/lsmsr ${PREFIX}/bin
	${INSTALL_MAN} ${MAN1:S,^,${WRKSRC}/,} ${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${MAN8:S,^,${WRKSRC}/,} ${MAN8PREFIX}/man/man8

.include <bsd.port.post.mk>
