# ex:ts=8
# Ports collection makefile for:	tipograf
# Date created:			Oct 29, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tipograf
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://www.falk-henrich.de/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI for a2ps

BUILD_DEPENDS=	a2ps:${PORTSDIR}/print/a2ps-letter
RUN_DEPENDS=	a2ps:${PORTSDIR}/print/a2ps-letter

USE_REINPLACE=	yes
USE_QT_VER=	3
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-qt-dir=${QT_PREFIX}
USE_GMAKE=	yes

post-extract:
	@(cd ${WRKSRC}/src && ${TOUCH} *.ui)

post-patch:
	@${REINPLACE_CMD} -e "s|-lqt|-lqt-mt|g" \
		-e "s|qt.so.3|qt-mt.so.3|g" \
		-e "s|qt.so|qt-mt.so|g" ${WRKSRC}/configure

.include <bsd.port.mk>
