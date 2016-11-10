# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	msort
PORTVERSION=	8.53
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://billposer.org/Software/Downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sorting files in sophisticated ways

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libtre.so:textproc/libtre \
		libuninum.so:devel/libuninum \
		libutf8proc.so:textproc/utf8proc
RUN_DEPENDS=	iwidgets>=0:x11-toolkits/iwidgets
TEST_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash

BROKEN_aarch64=	Fails to link: missing sbrk

CONFIGURE_ENV=	ac_cv_lib_tre_regwcomp=yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV+=	INCLUDES="-I${LOCALBASE}/include"
GNU_CONFIGURE=	yes
USES=		gettext tk:wrapper,run
TEST_TARGET=	test
TEST_ENV=	LC_ALL=C

PLIST_FILES=	bin/msg bin/msort man/man1/msort.1.gz

post-patch:
	@${REINPLACE_CMD} -e "s|bash|${LOCALBASE}/bin/bash|g" ${WRKSRC}/RegressionTests/Makefile
	@${REINPLACE_CMD} -e "s|msort|../&|g" ${WRKSRC}/RegressionTests/RunTests.sh \

.include <bsd.port.mk>
