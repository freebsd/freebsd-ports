# ex:ts=8
# New ports collection makefile for:	HDF5
# Date created:			Jul 7, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	hdf5
PORTVERSION=	1.4.4
CATEGORIES=	graphics
MASTER_SITES=	ftp://hdf.ncsa.uiuc.edu/HDF5/hdf5-${PORTVERSION}/src/

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes
USE_PERL5=	yes
USE_OPENSSL=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--enable-cxx --enable-production \
		--enable-threadsafe --disable-debug \
		--with-ssl --with-pthread
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e "s/-lpthread/${PTHREAD_LIBS}/g" ${WRKSRC}/configure

.include <bsd.port.mk>
