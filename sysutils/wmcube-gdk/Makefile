# Created by: Patrick Li <pat@databits.net>
# $FreeBSD$

PORTNAME=	wmcube
PORTVERSION=	0.98p2
PORTREVISION=	5
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://www.ne.jp/asahi/linux/timecop/software/
PKGNAMESUFFIX=	-gdk
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	A modified version of the dockapp wmCube

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS

USE_XORG=	xpm
USE_GNOME=	gtk12
MAKEFILE=	Makefile.FREEBSD
SUB_FILES=	pkg-message
NEED_ROOT=	yes

DATADIR=	${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
PORTDOCS=	CHANGES README README.GDK TODO

do-install:
	${INSTALL_PROGRAM} -m 2755 -o root -g kmem ${WRKSRC}/wmcube \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}${PKGNAMESUFFIX}
.for files in *.wmc
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/3dObjects/${files} ${STAGEDIR}${DATADIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
