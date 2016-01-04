# Created by: Michael A. Kohn <mike@mikekohn.net>
# $FreeBSD$

PORTNAME=	ringtonetools
PORTVERSION=	2.26
CATEGORIES=	misc
MASTER_SITES=	http://downloads.mikekohn.net/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create/convert/listen to ringtones and logos for mobile phones

RESTRICTED=	no-commercial-use

MAKE_ARGS=	CC="${CC}" FLAGS="${CFLAGS}"

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|cd src && make|make -C src|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ringtonetools ${STAGEDIR}${PREFIX}/bin
.for i in face.txt hemglass.mid ionian.rtttl usa.emelody yngwie_trilogy.rtttl
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/samples/${i} ${STAGEDIR}${DATADIR}
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
