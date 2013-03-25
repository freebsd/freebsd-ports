# Created by: Michael A. Kohn <mike@mikekohn.net>
# $FreeBSD$

PORTNAME=	ringtonetools
PORTVERSION=	2.25
CATEGORIES=	misc
MASTER_SITES=	http://downloads.mikekohn.net/${PORTNAME}/

MAINTAINER=	mike@mikekohn.net
COMMENT=	Create/Convert/Listen to ringtones and logos for mobile phones

RESTRICTED=	no-commercial-use

pre-build:
	@${REINPLACE_CMD} -e 's|^FLAGS|FLAGS?|' ${WRKSRC}/src/Makefile

.include <bsd.port.options.mk>

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/ringtonetools ${PREFIX}/bin
.for i in face.txt hemglass.mid ionian.rtttl usa.emelody yngwie_trilogy.rtttl
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/samples/${i} ${DATADIR}
.endfor

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
