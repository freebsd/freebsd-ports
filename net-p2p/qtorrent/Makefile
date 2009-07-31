# New ports collection makefile for:	qtorrent
# Date created:		2004-03-31
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	qtorrent
PORTVERSION=	0.9.6.1
PORTREVISION=	6
CATEGORIES=	net-p2p python
MASTER_SITES=	http://thegraveyard.org/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BitTorrent client that uses the Qt widget-set

PATCH_DEPENDS=	pyuic:${PORTSDIR}/x11-toolkits/py-qt
BUILD_DEPENDS=	pyuic:${PORTSDIR}/x11-toolkits/py-qt
RUN_DEPENDS=	pyuic:${PORTSDIR}/x11-toolkits/py-qt

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.if defined(PACKAGE_BUILDING)
TMPDIR?=	/tmp                
MAKE_ENV+=	TMPDIR="${TMPDIR}"      
CONFIGURE_ENV+=	TMPDIR="${TMPDIR}" 
.endif

pre-everything::
	@${ECHO_MSG} "===>"
	@${ECHO_MSG} "===> For qtorrent to work you need to compile"
	@${ECHO_MSG} "===> python WITH_THREADS defined, it is default"
	@${ECHO_MSG} "===>"

post-patch:
.for i in torrentsettings torrentwindow
	@${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/pyuic -o ${WRKSRC}/pyqtorrent/${i}.py ${WRKSRC}/pyqtorrent/${i}.ui
.endfor

.include <bsd.port.mk>
