# New ports collection makefile for:	wmcube
# Date created:				Mon May 28 02:14:47 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	wmcube
PORTVERSION=	0.98
PORTREVISION=	1
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://kling.mine.nu/files/

MAINTAINER=	pat@FreeBSD.org
COMMENT=	Window Maker dockapp that displays cpu load and a realtime 3d object

WRKSRC=		${WRKDIR}/${PORTNAME}/${PORTNAME}
USE_X_PREFIX=	yes
USE_XPM=	yes
MAKEFILE=	Makefile.FREEBSD

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/wmcube ${PREFIX}/bin
	@${CHMOD} g+s ${PREFIX}/bin/wmcube
	@${CHOWN} root:kmem ${PREFIX}/bin/wmcube

post-install:
.for file in *.wmc
	@${ECHO} "===>   Installing extra 3d objects in ${PREFIX}/share/${PORTNAME}"
	@${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 555 \
		${PREFIX}/share/${PORTNAME}
	@${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/3dObjects/${file} \
		${PREFIX}/share/${PORTNAME}
.endfor
.ifndef(NOPORTDOCS)
	@${ECHO} "===>   Installing README in ${PREFIX}/share/doc/${PORTNAME}"
	@${ECHO} "===>   Please Read pkg-descr and README for usage information"
	@${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 555 \
		${PREFIX}/share/doc/${PORTNAME}
.for file in CHANGES README TODO
	@${INSTALL_DATA} ${WRKSRC}/../${file} ${PREFIX}/share/doc/${PORTNAME}
.endfor
.endif # !NOPORTDOCS
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|" ${PKGMESSAGE}

.include <bsd.port.mk>
