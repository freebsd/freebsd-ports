# New ports collection makefile for:   vrweb
# Date created:        20 June 1997
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	vrweb
PORTVERSION= 	1.5
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.iicm.edu/pub/VRweb/UNIX/vrweb-1.5/ \
		ftp://ftp.sunet.se/pub/nir/Hyper-G/VRweb/UNIX/vrweb-1.5/ \
		ftp://metalab.unc.edu/pub/packages/infosystems/WWW/VRML/VRweb/UNIX/vrweb-1.5/
DISTFILES=	vrweb-src-1.5.tar.gz help-1.5.tar.gz

MAINTAINER=	saper@system.pl

LIB_DEPENDS=	GL.14:${PORTSDIR}/graphics/Mesa3

USE_GMAKE=	yes
USE_X_PREFIX=	yes

do-configure:
	(cd ${WRKSRC}; \
	${LN} -s `which ${GMAKE}` ${WRKSRC}/config/scripts/make; \
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

BROKEN=	"does not compile with recent Mesa"

.include <bsd.port.mk>
