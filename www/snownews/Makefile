# ex:ts=8
# New ports collection makefile for:	snownews
# Date created:			Nov 3 2003
# Whom:				Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	snownews
PORTVERSION=	1.4.2
CATEGORIES=	www
MASTER_SITES=	http://home.kcore.de/~kiza/software/snownews/download/

MAINTAINER=	clsung@dragon2.net
COMMENT=	A text mode RSS newsreader

BUILD_DEPENDS=	${LOCALBASE}/bin/xml2-config:${PORTSDIR}/textproc/libxml2
LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old \
		iconv.3:${PORTSDIR}/converters/libiconv

USE_GMAKE=	yes

MAN1=		snownews.1
MANLANG=	"" de nl fr it

.include <bsd.port.mk>
