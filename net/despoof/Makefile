# New ports collection makefile for:	despoof
# Date created:				02 September 2000
# Whom:					Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	despoof
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	http://razor.bindview.com/tools/files/ \
		${MASTER_SITE_PACKETSTORM}
MASTER_SITE_SUBDIR=	UNIX/misc
EXTRACT_SUFX=	.tgz

MAINTAINER=	roam@FreeBSD.org
COMMENT=	Command-line anti-spoofing detection utility

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/despoof ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/doc/despoof
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/despoof

.include <bsd.port.mk>
