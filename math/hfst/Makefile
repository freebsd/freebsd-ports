# Created by: Dmitry Sivachenko <mitya@yandex-team.ru>
# $FreeBSD$

PORTNAME=	hfst
PORTVERSION=	3.7.2
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=${PORTNAME}/${PORTNAME}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A toolkit for for processing natural language morphologies

USES=		pkgconfig shebangfix libtool python:2
USE_GNOME=	glib20 libxml2
USE_GCC=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-readline --with-unicode-handler=glib --enable-proc --enable-tagger --enable-xfst --enable-shuffle --enable-traverse
SHEBANG_FILES=	tools/src/hfst-tagger/src/hfst_tagger_compute_data_statistics.py
USE_LDCONFIG=	yes

.include <bsd.port.mk>
