# New ports collection makefile for:	barry
# Date created: 			19 September 2002
# Whom:					Brad Davis <so14k@so14k.com>
#
# $FreeBSD$
#

PORTNAME=	barry
PORTVERSION=	0.7
PORTREVISION=	2
CATEGORIES=	sysutils kde
MASTER_SITES=	http://www.student.uni-oldenburg.de/frerich.raabe/barry/ \
		http://freebsd.so14k.com/barry/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A nice KDE frontend to the ports system

BUILD_DEPENDS=	${LOCALBASE}/sbin/portsdb:${PORTSDIR}/sysutils/portupgrade
RUN_DEPENDS=	${LOCALBASE}/sbin/portsdb:${PORTSDIR}/sysutils/portupgrade

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool:15

post-patch:
	@${FIND} ${WRKSRC} -name "*.h" -and -not -name "linklocator.h" | \
		${XARGS} ${REINPLACE_CMD} -e 's/^};/}/g'
	@${REINPLACE_CMD} "s,-lpthread,${PTHREAD_LIBS},g" ${WRKSRC}/configure

pre-install:
	@${MKDIR} ${DESTDIR}${PREFIX}/share/applnk/Utilities

.include <bsd.port.mk>
