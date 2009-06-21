# New ports collection makefile for:	freedialog
# Date created:		30 October 1999
# Whom:			James Howard <ports@vocito.com>
#
# $FreeBSD$
#

PORTNAME=	freedialog
PORTVERSION=	0.3
CATEGORIES=	misc
MASTER_SITES=	http://www.vocito.com/downloads/software/dialog/
DISTNAME=	dialog-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An implementation of dialog(1) under a BSD-friendly license

BUILD_DEPENDS=	${LOCALBASE}/lib/libiberty.so:${PORTSDIR}/devel/freelibiberty

CFLAGS+=	-I${LOCALBASE}/include/freelibiberty

MAN1=		dialog.1
PLIST_FILES=	bin/dialog

post-extract:
	@(cd ${WRKSRC}; ${RM} -f .depend)

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
