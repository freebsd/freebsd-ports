# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libflate
PORTVERSION=	2.0
CATEGORIES=	textproc devel
MASTER_SITES=	http://flate.dead-inside.org/

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Template library used to deal with html code in CGI applications

PLIST_FILES=	lib/${PORTNAME}.a \
		bin/checktpl

.include <bsd.port.pre.mk>

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/checktpl ${PREFIX}/bin/
	@${INSTALL_LIB} ${WRKSRC}/${PORTNAME}.a ${PREFIX}/lib/

.include <bsd.port.post.mk>
