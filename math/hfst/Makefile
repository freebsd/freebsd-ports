# Created by: Dmitry Sivachenko <mitya@yandex-team.ru>
# $FreeBSD$

PORTNAME=	hfst
PORTVERSION=	3.8.2
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/source

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A toolkit for for processing natural language morphologies

USES=		libtool pkgconfig python:2 readline shebangfix
USE_GNOME=	glib20 libxml2
USE_GCC=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-readline --with-unicode-handler=glib --enable-calculate --enable-edit-metadata --enable-lexc-wrapper --enable-proc --enable-tagger --enable-xfst --enable-shuffle --enable-traverse
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libxml2
LDFLAGS+=	-L${LOCALBASE}/lib
SHEBANG_FILES=	tools/src/hfst-tagger/src/hfst_tagger_compute_data_statistics.py
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000033
BUILD_DEPENDS+=	flex>2.5.33:textproc/flex
CONFIGURE_ENV+=	LEX="${FLEX}"
FLEX=		${LOCALBASE}/bin/flex
.endif

.include <bsd.port.post.mk>
