# New ports collection makefile for:	msort
# Date created:		2006-08-11
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	msort
PORTVERSION=	8.53
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://billposer.org/Software/Downloads/

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Sorting files in sophisticated ways

LIB_DEPENDS=	tre:${PORTSDIR}/textproc/libtre \
    		uninum:${PORTSDIR}/devel/libuninum \
		utf8proc:${PORTSDIR}/textproc/utf8proc
RUN_DEPENDS=	iwidgets>=0:${PORTSDIR}/x11-toolkits/iwidgets

CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" CPPFLAGS="-I${LOCALBASE}/include" \
		ac_cv_lib_tre_regwcomp=yes
MAKE_ENV+=	INCLUDES="-I${LOCALBASE}/include"
GNU_CONFIGURE=	yes
USE_TK_RUN=	yes
USE_TCL_WRAPPER=	yes
USE_GETTEXT=	yes

PLIST_FILES=	bin/msg bin/msort

MAN1=		msort.1

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
