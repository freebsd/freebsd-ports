# New ports collection makefile for:	mad_fcl
# Date created:				03.02.2003
# Whom:					Janos.Mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	mad_fcl
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.atm.tut.fi/mad/download/
DISTNAME=	${PORTNAME}_v${PORTVERSION}_src

MAINTAINER=	Janos.Mohacsi@bsd.hu
COMMENT=	FLUTE - File Delivery over Unidirectional Transport implementation

LIB_DEPENDS=	expat.5:${PORTSDIR}/textproc/expat2

USE_GMAKE=	yes
USE_REINPLACE=	yes

CFLAGS+=	${PTHREAD_CFLAGS}

DOC_FILES=	fdt-example.xml flute-sdp-example.sdp

PORTDOCS=	${DOC_FILES} README.TXT
PLIST_FILES=	bin/flute

pre-patch:
	# Fixing the end-of-lines:
	for f in `${FIND} ${WRKSRC}/.. -type f` ; do \
		${TR} -d '\015' < $$f > $$f.noms && \
			${CAT} $$f.noms > $$f && ${RM} $$f.noms; done

post-patch:
	${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/flute/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/flute ${PREFIX}/bin
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/README.TXT ${DOCSDIR}
.endif

.include <bsd.port.mk>
