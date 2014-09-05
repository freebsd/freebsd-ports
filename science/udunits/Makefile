# Created by: Greg Lewis <glewis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	udunits
PORTVERSION=	2.2.17
CATEGORIES=	science math
MASTER_SITES=	ftp://ftp.unidata.ucar.edu/pub/udunits/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for manipulating units of physical quantities

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2

OPTIONS_DEFINE=	DOCS

CONFIGURE_ENV=	ac_cv_header_CUnit_CUnit_h=no
CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV=	INSTALL_STRIP_FLAG=${STRIP}
USE_LDCONFIG=	yes
USES=		libtool

INFO=		udunits2 udunits2lib udunits2prog
PORTDATA=	*
PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e '/install-data-hook$$/d' ${WRKSRC}/lib/Makefile.in

regression-test test: build
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check

.include <bsd.port.mk>
