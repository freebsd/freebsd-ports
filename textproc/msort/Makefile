# New ports collection makefile for:	msort
# Date created:		2006-08-11
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	msort
PORTVERSION=	8.27
CATEGORIES=	textproc
MASTER_SITES=	http://billposer.org/Software/Downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	gslin@gslin.org
COMMENT=	Sorting files in sophisticated ways

BUILD_DEPENDS=	${RUN_DEPENDS}
LIB_DEPENDS=	tre:${PORTSDIR}/textproc/libtre
RUN_DEPENDS=	iwidgets>=0:${PORTSDIR}/x11-toolkits/iwidgets

CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"
GNU_CONFIGURE=	yes
USE_TK=		yes

PLIST_FILES=	bin/msg bin/msort

MAN1=		msort.1

post-patch:
	${REINPLACE_CMD} -e 's,^#include <alloca.h>,,g' ${WRKSRC}/msort.c

.include <bsd.port.mk>
