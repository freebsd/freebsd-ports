# New ports collection makefile for:	netsaint
# Date created:				Wed 12 Jul 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	netsaint
PORTVERSION=	0.0.5.2
CATEGORIES=	net
MASTER_SITES=	http://www.netsaint.org/download/
DISTNAME=	${PORTNAME}-0.0.5-2

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	gd.1:${PORTSDIR}/graphics/gd

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lgd"
INSTALL_TARGET=	install-all

pre-fetch:
	@${SH} ${SCRIPTDIR}/checkps

pre-install:
	${PERL} ${SCRIPTDIR}/createuser
	${PERL} -pi -e "s@/bin/echo@echo@g" ${WRKSRC}/hosts.cfg.in

.include <bsd.port.mk>
