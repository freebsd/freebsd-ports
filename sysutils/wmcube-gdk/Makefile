# New ports collection makefile for:	wmcube-gdk
# Date created:				Thu Aug 16 12:42:18 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	wmcube
PORTVERSION=	0.98p2
PORTREVISION=	2
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://www.ne.jp/asahi/linux/timecop/software/
PKGNAMESUFFIX=	-gdk
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	pat@FreeBSD.org
COMMENT=	wmcube-gdk is a modified version of the dockapp wmCube

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GNOME=	gtk12
MAKEFILE=	Makefile.FREEBSD

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/wmcube \
		${PREFIX}/bin/wmcube-gdk
	@${CHMOD} g+s ${PREFIX}/bin/wmcube-gdk
	@${CHOWN} root:kmem ${PREFIX}/bin/wmcube-gdk

post-install:
.for files in *.wmc
	@${MKDIR} ${DATADIR}${PKGNAMESUFFIX}
	@${INSTALL_DATA} ${WRKSRC}/3dObjects/${files} \
		${DATADIR}${PKGNAMESUFFIX}
.endfor
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}${PKGNAMESUFFIX}
.for file in CHANGES README README.GDK TODO
	@${INSTALL_DATA} ${WRKSRC}/${file} \
		${DOCSDIR}${PKGNAMESUFFIX}
.endfor
.endif #NOPORTDOCS
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|" ${PKGMESSAGE}

.include <bsd.port.mk>
