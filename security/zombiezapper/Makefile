# Ports collection makefile for:  zombiezapper
# Date created:			  19 Feb 2000
# Whom:				  Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	zombiezapper
PORTVERSION=	1.2
CATEGORIES=	security
MASTER_SITES=	http://razor.bindview.com/tools/files/
DISTNAME=	zombie-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	roam@FreeBSD.org
COMMENT=	Send a terminate command to Trinoo/TFN/Stacheldracht DDoS agents

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
