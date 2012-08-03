# New ports collection makefile for:	wmcube-gdk
# Date created:				Thu Aug 16 12:42:18 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	wmcube
PORTVERSION=	0.98p2
PORTREVISION=	5
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://www.ne.jp/asahi/linux/timecop/software/
PKGNAMESUFFIX=	-gdk
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	A modified version of the dockapp wmCube

OPTIONS_DEFINE=	DOCS

USE_XORG=	xpm
USE_GNOME=	gtk12
MAKEFILE=	Makefile.FREEBSD
SUB_FILES=	pkg-message
MAKE_JOBS_SAFE=	yes

DATADIR=	${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
PORTDOCS=	CHANGES README README.GDK TODO

.include <bsd.port.pre.mk>

do-install:
	@${INSTALL_PROGRAM} -m 2755 -o root -g kmem ${WRKSRC}/wmcube \
		${PREFIX}/bin/${PORTNAME}${PKGNAMESUFFIX}

post-install:
.for files in *.wmc
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/3dObjects/${files} ${DATADIR}
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
. for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
. endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
