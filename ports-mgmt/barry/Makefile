# New ports collection makefile for:	barry
# Date created: 			19 September 2002
# Whom:					Brad Davis <so14k@so14k.com>
#
# $FreeBSD$
#

PORTNAME=	barry
PORTVERSION=	0.7
PORTREVISION=	5
CATEGORIES=	ports-mgmt kde
MASTER_SITES=	http://www.student.uni-oldenburg.de/frerich.raabe/barry/ \
		http://freebsd.so14k.com/barry/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A nice KDE frontend to the ports system

BUILD_DEPENDS=	${LOCALBASE}/sbin/portsdb:${PORTSDIR}/ports-mgmt/portupgrade
RUN_DEPENDS=	${LOCALBASE}/sbin/portsdb:${PORTSDIR}/ports-mgmt/portupgrade

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool:22
INSTALLS_ICONS=	yes
USE_GETTEXT=	yes

NO_LATEST_LINK=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=		Broken with gcc 4.2
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "*.h" -and -not -name "linklocator.h" | \
		${XARGS} ${REINPLACE_CMD} -e 's/^};/}/g'
	@${REINPLACE_CMD} "s,-lpthread,${PTHREAD_LIBS},g" ${WRKSRC}/configure

pre-install:
	@${MKDIR} ${PREFIX}/share/applnk/Utilities

.include <bsd.port.post.mk>
