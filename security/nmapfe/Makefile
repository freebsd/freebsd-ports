# ex:ts=8
# Ports collection makefile for:  nmap
# Date created:			  Tue Aug 04, 1998
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	nmapfe
PORTVERSION=	0.9.5
CATEGORIES=	security
MASTER_SITES=	http://codebox.net/download/  \
		http://www.insecure.org/nmap/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	obrien@FreeBSD.org

RUN_DEPENDS=	nmap:${PORTSDIR}/security/nmap

.include <bsd.port.pre.mk>

USE_XLIB=	yes
USE_GTK=	yes
GNU_CONFIGURE=	yes
WRKSRC:=	${WRKDIR}/nmapfe

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nmapfe ${PREFIX}/bin
	cd ${PREFIX}/bin && ${LN} -f nmapfe xnmap

.include <bsd.port.post.mk>
