# New ports collection makefile for:	youbin
# Date created:			09 Aug 1996
# Whom:				Masafumi NAKANE <max@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	youbin
PORTVERSION=	3.4
CATEGORIES=	mail
MASTER_SITES=	http://www.agusa.nuie.nagoya-u.ac.jp/software/agusalab/youbin/archive/
DISTNAME=	${PORTNAME}${PORTVERSION}-unix

MAINTAINER=	max@FreeBSD.org

USE_IMAKE=		yes
USE_X_PREFIX=		no
USE_XPM=		yes
WRKSRC=			${WRKDIR}/Youbin-Unix
NO_INSTALL_MANPAGES=	yes

SAMPLE_SCRIPTS=		youbind.sh.sample xyoubin.sh

pre-build:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGREQ} ${PKGNAME} BUILD

pre-install:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGREQ} ${PKGNAME} INSTALL

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/youbin
	${INSTALL_DATA} ${WRKSRC}/Doc/* ${PREFIX}/share/doc/youbin
.endif
	${MKDIR} ${PREFIX}/share/examples/youbin/Bitmap
	${INSTALL_DATA} ${WRKSRC}/Bitmap/* ${PREFIX}/share/examples/youbin/Bitmap
.for f in ${SAMPLE_SCRIPTS}
	${SED} s:@PREFIX@:${PREFIX}: ${FILESDIR}/$f \
	  > ${PREFIX}/share/examples/youbin/$f
	${CHMOD} 755 ${PREFIX}/share/examples/youbin/$f
.endfor
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
