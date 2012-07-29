# New ports collection makefile for:	wmcube
# Date created:				Mon May 28 02:14:47 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	wmcube
PORTVERSION=	0.98
PORTREVISION=	3
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	${MASTER_SITE_TUCOWS} \
		http://dockapps.org/download.php/id/222/ \
		http://freebsd.unixfreunde.de/sources/
MASTER_SITE_SUBDIR=	x11/dock

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Window Maker dockapp that displays cpu load and a realtime 3D object

WRKSRC=		${WRKDIR}/${PORTNAME}/${PORTNAME}
USE_XORG=	xpm
MAKEFILE=	Makefile.FREEBSD
PORTDOCS=	CHANGES README TODO
SUB_FILES=	pkg-message
USE_CSTD=	gnu89
MAKE_JOBS_UNSAFE=	yes

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/wmcube ${PREFIX}/bin
	@${CHMOD} g+s ${PREFIX}/bin/wmcube
	@${CHOWN} root:kmem ${PREFIX}/bin/wmcube

post-install:
.for file in *.wmc
	@${ECHO} "===>   Installing extra 3d objects in ${PREFIX}/share/${PORTNAME}"
	@${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 555 ${DATADIR}
	@${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/3dObjects/${file} ${DATADIR}
.endfor
.ifndef(NOPORTDOCS)
	@${ECHO} "===>   Installing README in ${PREFIX}/share/doc/${PORTNAME}"
	@${ECHO} "===>   Please Read pkg-descr and README for usage information"
	@${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 555 ${DOCSDIR}
. for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/../${f} ${DOCSDIR}
. endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
