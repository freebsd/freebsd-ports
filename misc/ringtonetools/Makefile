# Created by: Michael A. Kohn <mike@mikekohn.net>
# $FreeBSD$

PORTNAME=	ringtonetools
PORTVERSION=	2.26
CATEGORIES=	misc
MASTER_SITES=	http://downloads.mikekohn.net/${PORTNAME}/

MAINTAINER=	mike@mikekohn.net
COMMENT=	Create/convert/listen to ringtones and logos for mobile phones

RESTRICTED=	no-commercial-use

MAKE_ARGS=	CC="${CC}" FLAGS="${CFLAGS}"

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|cd src && make|make -C src|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ringtonetools ${PREFIX}/bin
.for i in face.txt hemglass.mid ionian.rtttl usa.emelody yngwie_trilogy.rtttl
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/samples/${i} ${DATADIR}
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
