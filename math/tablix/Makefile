# Created by: amir.husaini@gmail.com
# $FreeBSD$

PORTNAME=	tablix2
PORTVERSION=	0.3.5
PORTREVISION=	3
CATEGORIES=	math www
MASTER_SITES=	http://www.tablix.org/releases/stable/ \
		http://my.samba.org/

MAINTAINER=	amir.husaini@gmail.com
COMMENT=	Free software for solving timetabling problems

BUILD_DEPENDS=	pvm:${PORTSDIR}/net/pvm
RUN_DEPENDS=	pvm:${PORTSDIR}/net/pvm

PVM_ROOT=	${PREFIX}/lib/pvm

USE_GMAKE=	yes
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes
USES=		gettext

CONFIGURE_ENV=	LIBS=-L${PREFIX}/lib \
		PVM_ROOT=${PVM_ROOT} PVM_LIB=${PREFIX}/lib
CPPFLAGS+=	-I${PREFIX}/include
LDFLAGS+=	-L${PREFIX}/lib

MAN1=	tablix2.1 tablix2_benchmark.1 tablix2_kernel.1 tablix2_output.1 \
	tablix2_plot.1 tablix2_test.1

NO_STAGE=	yes
post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/tablix2 ${PVM_ROOT}/bin/FREEBSD/tablix2
	${INSTALL_SCRIPT} ${WRKSRC}/src/tablix2_kernel ${PVM_ROOT}/bin/FREEBSD/tablix2_kernel
	${INSTALL_SCRIPT} ${WRKSRC}/src/tablix2_output ${PVM_ROOT}/bin/FREEBSD/tablix2_output

.include <bsd.port.mk>
