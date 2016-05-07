# Created by: amir.husaini@gmail.com
# $FreeBSD$

PORTNAME=	tablix2
PORTVERSION=	0.3.5
PORTREVISION=	5
CATEGORIES=	math www
MASTER_SITES=	http://www.tablix.org/releases/stable/ \
		http://my.samba.org/

MAINTAINER=	amir.husaini@gmail.com
COMMENT=	Free software for solving timetabling problems

BUILD_DEPENDS=	pvm:net/pvm
RUN_DEPENDS=	pvm:net/pvm

PVM_ROOT=	${LOCALBASE}/lib/pvm

USE_GNOME=	libxml2
GNU_CONFIGURE=	yes
USES=		gettext gmake libtool shebangfix
SHEBANG_FILES=	${WRKSRC}/utils/tablix2_plot \
		${WRKSRC}/utils/tablix2_benchmark \
		${WRKSRC}/ttf/tablix2_test

CONFIGURE_ENV=	PVM_ROOT=${PVM_ROOT} PVM_LIB=${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

post-install:
	${MKDIR} ${STAGEDIR}${PVM_ROOT}/bin/FREEBSD
	${INSTALL_SCRIPT} ${WRKSRC}/src/tablix2 ${STAGEDIR}${PVM_ROOT}/bin/FREEBSD/tablix2
	${INSTALL_SCRIPT} ${WRKSRC}/src/tablix2_kernel ${STAGEDIR}${PVM_ROOT}/bin/FREEBSD/tablix2_kernel
	${INSTALL_SCRIPT} ${WRKSRC}/src/tablix2_output ${STAGEDIR}${PVM_ROOT}/bin/FREEBSD/tablix2_output

.include <bsd.port.mk>
