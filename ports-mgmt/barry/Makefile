# New ports collection makefile for:	barry
# Date created: 			19 September 2002
# Whom:					Brad Davis <so14k@so14k.com>
#
# $FreeBSD$
#

PORTNAME=	barry
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	sysutils kde
MASTER_SITES=	http://www.student.uni-oldenburg.de/frerich.raabe/barry/ \
		http://freebsd.so14k.com/barry/

MAINTAINER=	so14k@so14k.com
COMMENT=	A nice KDE frontend to the ports system

BUILD_DEPENDS=	${LOCALBASE}/sbin/portsdb:${PORTSDIR}/sysutils/portupgrade
RUN_DEPENDS=	${LOCALBASE}/sbin/portsdb:${PORTSDIR}/sysutils/portupgrade

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
BROKEN=		"Does not compile on FreeBSD >= 5.x"
.endif

pre-build:
	${REINPLACE_CMD} "s,-pthread,${PTHREAD_LIBS},g" ${WRKSRC}/Makefile

pre-install:
	${MKDIR} ${DESTDIR}${PREFIX}/share/applnk/Utilities

.include <bsd.port.post.mk>
