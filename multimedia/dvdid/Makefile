# Created by: Christopher Key <cjk32@cam.ac.uk>
# $FreeBSD$

PORTNAME=	dvdid
PORTVERSION=	0.2.0a
CATEGORIES=	multimedia
MASTER_SITES=	http://dvdid.cjkey.org.uk/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Tool for calculating dvdids

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|doc||' ${WRKSRC}/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} dvdid.tag ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/html/api
	cd ${WRKSRC}/doc/html/api && ${INSTALL_DATA} * ${DOCSDIR}/html/api
.endif

.include <bsd.port.mk>
