# ex:ts=8
# Ports collection makefile for:	gambit
# Date created:			Feb 8, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gambit
PORTVERSION=	0.97.0.3
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library of tools for doing computation in game theory

LIB_DEPENDS=	wx_gtk.2:${PORTSDIR}/x11-toolkits/wxgtk-devel

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

post-patch:
	@${GREP} -lR "values\.h" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-e "s|values\.h|limits.h|"
	@${GREP} -lR "malloc\.h" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-e "s|malloc\.h|stdlib.h|"

.include <bsd.port.mk>
