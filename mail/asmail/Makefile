# New ports collection makefile for:	 asmail
# Date created:		15 August 1997
# Whom:			brett@peloton.physics.montana.edu
#
# $FreeBSD$
#

PORTNAME=	asmail
PORTVERSION= 	0.54
CATEGORIES=	mail afterstep
MASTER_SITES=	http://www.tigr.net/afterstep/as-apps/download/asmail/ \
		ftp://ftp.afterstep.org/apps/asmail/

MAINTAINER=	brett@peloton.runet.edu

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
CONFIGURE_ARGS=	--enable-shaping

MAN1=	asmail.1

post-install:
	@${MKDIR} ${PREFIX}/include/X11/pixmaps/cloud-e
	@${INSTALL_DATA} ${WRKSRC}/pixmaps/cloud-e/*.xpm ${PREFIX}/include/X11/pixmaps/cloud-e
	@${INSTALL_DATA} ${WRKSRC}/pixmaps/*.xpm ${PREFIX}/include/X11/pixmaps
	@${INSTALL_MAN} ${WRKSRC}/asmail.man ${PREFIX}/man/man1/asmail.1
	@${MKDIR} ${PREFIX}/share/doc/asmail
	@${INSTALL_DATA} ${WRKSRC}/sample.asmailrc ${PREFIX}/share/doc/asmail
	@strip ${PREFIX}/bin/asmail
.if !defined(NOPORTDOCS)
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/asmail
	@${ECHO} "===>   README installed in ${PREFIX}/share/doc/asmail"
.endif

.include <bsd.port.mk>
