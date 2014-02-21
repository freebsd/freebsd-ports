# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	msort
PORTVERSION=	8.53
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://billposer.org/Software/Downloads/

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Sorting files in sophisticated ways

LICENSE=	GPLv3

LIB_DEPENDS=	libtre.so:${PORTSDIR}/textproc/libtre \
    		libuninum.so:${PORTSDIR}/devel/libuninum \
		libutf8proc.so:${PORTSDIR}/textproc/utf8proc
RUN_DEPENDS=	iwidgets>=0:${PORTSDIR}/x11-toolkits/iwidgets

CONFIGURE_ENV=	ac_cv_lib_tre_regwcomp=yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV+=	INCLUDES="-I${LOCALBASE}/include"
GNU_CONFIGURE=	yes
USES=		gettext tk:wrapper,run

PLIST_FILES=	bin/msg bin/msort man/man1/msort.1.gz

.ifdef(MAINTAINER_MODE)
BUILD_DEPENDS+= ${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash

post-patch:
	${REINPLACE_CMD} -e "s|bash|${LOCALBASE}/bin/bash|g" ${WRKSRC}/RegressionTests/Makefile
	${REINPLACE_CMD} -e "s|msort|../&|g" ${WRKSRC}/RegressionTests/RunTests.sh \
		${WRKSRC}/RegressionTests/RunLocaleTests.sh

test: build
	@(cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} test)

.endif

.include <bsd.port.mk>
