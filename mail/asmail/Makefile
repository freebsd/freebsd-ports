# New ports collection makefile for:	 asmail
# Date created:		15 August 1997
# Whom:			brett@peloton.physics.montana.edu
#
# $FreeBSD$
#

PORTNAME=	asmail
PORTVERSION=	0.56
CATEGORIES=	mail afterstep
MASTER_SITES=	http://asmail.sourceforge.net/files/ \
		ftp://gates.enemy.at/pub/

MAINTAINER=	brett@peloton.runet.edu

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shaping

MAN1=	asmail.1

post-patch:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/sample.asmailrc

post-install:
	${INSTALL_MAN} ${WRKSRC}/asmail.man ${PREFIX}/man/man1/asmail.1
	@${MKDIR} ${PREFIX}/include/X11/pixmaps/cloud-e
	${INSTALL_DATA} ${WRKSRC}/pixmaps/cloud-e/*.xpm ${PREFIX}/include/X11/pixmaps/cloud-e
	${INSTALL_DATA} ${WRKSRC}/pixmaps/*.xpm ${PREFIX}/include/X11/pixmaps
	@${MKDIR} ${PREFIX}/share/examples/asmail
	${INSTALL_DATA} ${WRKSRC}/sample.asmailrc ${PREFIX}/share/examples/asmail
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/asmail
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/asmail
.endif

.include <bsd.port.mk>
