# ex:ts=8
# Ports collection makefile for:  nmap
# Version required: 0.0
# Date created:			  Tue Aug 04, 1998
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

DISTNAME=	nmapfe-0.9.5
CATEGORIES=	security net
MASTER_SITES=	http://codebox.net/download/  \
		http://www.insecure.org/nmap/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	obrien@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12
RUN_DEPENDS=	nmap:${PORTSDIR}/security/nmap

.include <bsd.port.pre.mk>

USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG="${X11BASE}/bin/gtk12-config"
WRKSRC:=	${WRKDIR}/nmapfe

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nmapfe ${PREFIX}/bin
	cd ${PREFIX}/bin && ${LN} -f nmapfe xnmap

.include <bsd.port.post.mk>
