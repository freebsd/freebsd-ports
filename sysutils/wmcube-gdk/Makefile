# New ports collection makefile for:	wmcube-gdk
# Date created:				Thu Aug 16 12:42:18 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	wmcube
PORTVERSION=	0.98
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://www.ne.jp/asahi/linux/timecop/
PKGNAMESUFFIX=	-gdk
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}

MAINTAINER=	pat@databits.net

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GTK=	yes
MAKEFILE=	Makefile.FREEBSD

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/wmcube \
		${PREFIX}/bin/wmcube-gdk
	@${CHMOD} g+s ${PREFIX}/bin/wmcube-gdk
	@${CHOWN} root:kmem ${PREFIX}/bin/wmcube-gdk

post-install:
.for files in *.wmc
	@${MKDIR} ${PREFIX}/share/${DISTNAME}
	@${INSTALL_DATA} ${WRKSRC}/3dObjects/${files} \
		${PREFIX}/share/${DISTNAME}
.endfor
.ifndef(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/${DISTNAME}
.for file in CHANGES README README.GDK TODO
	@${INSTALL_DATA} ${WRKSRC}/${file} \
		${PREFIX}/share/doc/${DISTNAME}
.endfor
.endif #NOPORTDOCS
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|" ${PKGMESSAGE}

.include <bsd.port.mk>
