# ex:ts=8
# New ports collection makefile for:	snownews
# Date created:			Nov 3 2003
# Whom:				Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	snownews
PORTVERSION=	1.5.1
CATEGORIES=	www
MASTER_SITES=	http://home.kcore.de/~kiza/software/snownews/download/

MAINTAINER=	clsung@dragon2.net
COMMENT=	A text mode RSS newsreader

BUILD_DEPENDS=	${LOCALBASE}/bin/xml2-config:${PORTSDIR}/textproc/libxml2

USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_REINPLACE=	yes

MAN1=		snownews.1
MANLANG=	"" de nl fr it

post-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS =|CFLAGS +=|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
