# Ports collection makefile for:  zombiezapper
# Date created:			  19 Feb 2000
# Whom:				  Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	zombiezapper
PORTVERSION=	1.0
CATEGORIES=	security
MASTER_SITES=	http://razor.bindview.com/tools/files/
DISTNAME=	zombie
EXTRACT_SUFX=	.tar

MAINTAINER=	roam@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/bin/libnet-config:${PORTSDIR}/net/libnet/

LIBNETCONF=	${LOCALBASE}/bin/libnet-config

do-build:
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} -o zz zz.c `${LIBNETCONF} --cflags` `${LIBNETCONF} --defines` `${LIBNETCONF} --libs` -L${LOCALBASE}/lib -I${LOCALBASE}/include

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zz ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/zz/
	${INSTALL_DATA} ${WRKSRC}/USAGE ${PREFIX}/share/doc/zz/
	${INSTALL_DATA} ${WRKSRC}/tekpaper.txt ${PREFIX}/share/doc/zz/
.endif

.include <bsd.port.mk>
