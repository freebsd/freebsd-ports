# New ports collection makefile for:   kannel
# Date created:		19 Jun 2000
# Whom:			Domas Mituzas <midom@dammit.lt>
#
# $FreeBSD$

PORTNAME=	kannel
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.kannel.3glab.org/download/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}
DISTNAME=	gateway-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WAP / SMS Gateway

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2

USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}"
CONFIGURE_ARGS=	--with-malloc=native --enable-start-stop-daemon=no

MAN1=		seewbmp.1 wmlsc.1 wmlsdasm.1
MAN8=		kannel.8 run_kannel_box.8

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lc_r|${PTHREAD_LIBS:S/"//g}|g' ${WRKSRC}/configure

post-install:
.for file in gw/wapkannel.conf gw/smskannel.conf
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/etc
.endfor
.for file in seewbmp wmlsc wmlsdasm
	@${STRIP_CMD} ${PREFIX}/bin/${file}
.endfor
.for file in bearerbox run_kannel_box smsbox wapbox
	@${STRIP_CMD} ${PREFIX}/sbin/${file}
.endfor

.include <bsd.port.mk>
