# New ports collection makefile for:	unieject
# Date created:		23 July 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	unieject
DISTVERSION=	5.3.2
CATEGORIES=	sysutils
MASTER_SITES=	SF BERLIOS

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Eject(1) replacement

LIB_DEPENDS=	cdio.7:${PORTSDIR}/sysutils/libcdio \
		confuse.0:${PORTSDIR}/devel/libconfuse \
		popt.0:${PORTSDIR}/devel/popt

BROKEN=		Configure fails

USE_GNOME=	pkgconfig
USE_LDCONFIG=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
MAN1=	unieject.1
MAN5=	unieject.conf.5

CONFIGURE_ENV=	CONFUSE_CFLAGS="-I${LOCALBASE}/include" \
		CONFUSE_LIBS="-L${LOCALBASE}/lib -lconfuse"
CONFIGURE_ARGS=	--with-libintl-prefix=${LOCALBASE} \
		--with-libpopt-prefix=${LOCALBASE} --mandir=${MANPREFIX}/man

post-patch:
	${REINPLACE_CMD} -e 's#if.*<<<$$DOXYFORMATS#if false#' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's#$$(libdir)/pkgconfig#${PREFIX}/libdata/pkgconfig#' ${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -Ee 's#install-htmlDATA (install-man)#\1#' ${WRKSRC}/manpages/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/unieject.conf.sample ${PREFIX}/etc/

.include <bsd.port.mk>
