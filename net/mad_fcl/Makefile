# Created by: Janos.Mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	mad_fcl
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.atm.tut.fi/mad/download/
DISTNAME=	${PORTNAME}_v${PORTVERSION}_src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FLUTE - File Delivery over Unidirectional Transport implementation

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2

USES=		gmake
USE_OPENSSL=	yes

DOC_FILES=	fdt-example.xml flute-sdp-example.sdp

PORTDOCS=	${DOC_FILES} README.TXT
PLIST_FILES=	bin/flute

MAKE_JOBS_UNSAFE= yes

OPTIONS_DEFINE=	DOCS

pre-patch:
	# Fixing the end-of-lines:
	@for f in `${FIND} ${WRKSRC}/.. -type f` ; do \
		${TR} -d '\015' < $$f > $$f.noms && \
			${CAT} $$f.noms > $$f && ${RM} $$f.noms; done

post-patch:
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} \
		${REINPLACE_CMD} -e 's|gcc|${CC}|'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/flute ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${STAGEDIR}${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/README.TXT ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
