# New ports collection makefile for:   vrweb
# Version required:    1.5
# Date created:        20 June 1997
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.4 1998/04/23 16:50:35 mph Exp $
#

DISTNAME=	vrweb-1.5
CATEGORIES=	www
MASTER_SITES=	http://sunsite.unc.edu/pub/packages/infosystems/WWW/VRML/VRweb/UNIX/vrweb-1.5/
DISTFILES=	vrweb-src-1.5.tar.gz help-1.5.tar.gz

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp

LIB_DEPENDS=	GL\\.13\\.:${PORTSDIR}/graphics/Mesa2

USE_GMAKE=	yes
USE_X11=	yes

do-configure:
	(cd ${WRKSRC}; \
	ln -s `which ${GMAKE}` ${WRKSRC}/config/scripts/make; \
	${WRKSRC}/makeall -r; \
	${WRKSRC}/makeall -m; )

do-build:
	(cd ${WRKSRC}; \
	${WRKSRC}/makeall -i; )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/installed/harmony/bin/FREEBSD/vrweb-mesa \
		 ${PREFIX}/bin/vrweb
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/vrweb
	${CP} -R ${WRKDIR}/help/* ${PREFIX}/share/doc/vrweb
	${MKDIR} ${PREFIX}/share/doc/vrweb/icons
	${CP} ${WRKDIR}/icons/* ${PREFIX}/share/doc/vrweb/icons
.endif

.include <bsd.port.mk>
