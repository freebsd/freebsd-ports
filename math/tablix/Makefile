# Created by: amir.husaini@gmail.com
# $FreeBSD$

PORTNAME=	tablix2
PORTVERSION=	0.3.5
PORTREVISION=	4
CATEGORIES=	math www
MASTER_SITES=	http://www.tablix.org/releases/stable/ \
		http://my.samba.org/

MAINTAINER=	amir.husaini@gmail.com
COMMENT=	Free software for solving timetabling problems

BUILD_DEPENDS=	pvm:${PORTSDIR}/net/pvm
RUN_DEPENDS=	pvm:${PORTSDIR}/net/pvm

PVM_ROOT=	${LOCALBASE}/lib/pvm

USE_GNOME=	libxml2
GNU_CONFIGURE=	yes
USES=		gettext gmake

CONFIGURE_ENV=	PVM_ROOT=${PVM_ROOT} PVM_LIB=${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

MAN1=	tablix2.1 tablix2_benchmark.1 tablix2_kernel.1 tablix2_output.1 \
	tablix2_plot.1 tablix2_test.1

NO_STAGE=	yes
post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/tablix2 ${PVM_ROOT}/bin/FREEBSD/tablix2
	${INSTALL_SCRIPT} ${WRKSRC}/src/tablix2_kernel ${PVM_ROOT}/bin/FREEBSD/tablix2_kernel
	${INSTALL_SCRIPT} ${WRKSRC}/src/tablix2_output ${PVM_ROOT}/bin/FREEBSD/tablix2_output

.include <bsd.port.mk>
