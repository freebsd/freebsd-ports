# ex:ts=8
# Ports collection makefile for:  nmap
# Version required:     	  1.51
# Date created:			  Tue Aug 04, 1998
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

DISTNAME=	nmap-2.3BETA5
PKGNAME=	nmapfe-19990907
CATEGORIES=	security net
MASTER_SITES=	http://www.insecure.org/nmap/dist/  \
		ftp://relay.nuxi.com/pub/misc/
EXTRACT_SUFX=	.tgz

MAINTAINER=     obrien@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12
RUN_DEPENDS=	nmap:${PORTSDIR}/security/nmap

.include <bsd.port.pre.mk>

USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --libdir=${PREFIX}/share/misc
MAKE_ENV=	GTK_CONFIG="${X11BASE}/bin/gtk12-config"

post-extract:
	@${RM} -rf ${WRKSRC}/libpcap*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nmapfe/nmapfe ${PREFIX}/bin
	cd ${PREFIX}/bin && ${LN} -f nmapfe xnmap

.include <bsd.port.post.mk>
