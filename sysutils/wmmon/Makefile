# New ports collection makefile for:   wmmon
# Version required:    1.0b2
# Date created:        27 November 1998
# Whom:                Kris Kennaway <kkennawa@physics.adelaide.edu.au>
#
# $Id: Makefile,v 1.2 1998/12/16 04:51:54 flathill Exp $
#

DISTNAME=	wmmon-1.0b2
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.mezaway.org/pub/ \
		http://www.physics.adelaide.edu.au/~kkennawa/ \
		ftp://ftp.tecnogi.com/pub/linux/WindowMaker/ \
		ftp://ftp.deva.net/pub/sources/X11/WindowMaker/dockapps/ \
		ftp://ftp.paco.odessa.ua/.2/x11/wm/WindowMaker/apps/
DISTFILES=	wmmon-1.0b2.tar.gz wmmon-1.0b2-freebsd.tar.gz

MAINTAINER=	kkennawa@physics.adelaide.edu.au

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=   yes

WRKSRC=		${WRKDIR}/wmmon.app/wmmon

.include <bsd.port.pre.mk>

pre-patch:
	@cd ${WRKDIR}/wmmon.app && ${PATCH} -p < ${WRKDIR}/wmmon-freebsd.patch

post-patch:
.if ${OSVERSION} >= 300000
	@${CP} ${WRKDIR}/wmmon/Makefile.FreeBSD-3.0 ${WRKSRC}/Makefile
.else
	@${CP} ${WRKDIR}/wmmon/Makefile.FreeBSD-2.2 ${WRKSRC}/Makefile
.endif

post-install:
	@strip ${PREFIX}/bin/wmmon

.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/wmmon
	${INSTALL_MAN} ${WRKSRC}/../HINTS ${PREFIX}/share/doc/wmmon
.endif

.include <bsd.port.post.mk>
