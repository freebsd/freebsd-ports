# Created by: smace@FreeBSD.org
# $FreeBSD$

PORTNAME=	pnm2ppa
PORTVERSION=	1.13
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	SF

MAINTAINER=	000.fbsd@quip.cz
COMMENT=	Convert PNM images to PPA for some HP printers

OPTIONS_DEFINE=	A4SIZE
A4SIZE_DESC=	Set A4 (not Letter) as a default paper size

USES=	gmake ghostscript:run
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if defined(A4) || !empty(PORT_OPTIONS:MA4SIZE)
RUN_DEPENDS=	enscript:print/enscript-a4
.else
RUN_DEPENDS=	enscript:print/enscript-letter
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-Wformat-security -g|-Wformat-security| ; \
		 s|-O2 -DNDEBUG|-DNDEBUG|' ${WRKSRC}/configure
	@${SED} -e "s:%%PREFIX%%:${PREFIX}:g" \
		${WRKSRC}/pnm2ppa.conf > ${WRKSRC}/pnm2ppa.conf.sample
	@${SED} -e "s:%%PREFIX%%:${PREFIX}:g" \
		${WRKSRC}/docs/en/pnm2ppa.1 > ${WRKSRC}/pnm2ppa.1
	@${SED} -e "s:%%PREFIX%%:${PREFIX}:g" \
	        -e "s:%%LOCALBASE%%:${LOCALBASE}:g" \
		${FILESDIR}/asciippafilter.SH > ${WRKSRC}/asciippafilter
	@${SED} -e "s:%%PREFIX%%:${PREFIX}:g" \
	        -e "s:%%LOCALBASE%%:${LOCALBASE}:g" \
		${FILESDIR}/ppafilter.SH > ${WRKSRC}/ppafilter

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/calibrate_ppa ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/pnm2ppa ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/asciippafilter ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ppafilter ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pnm2ppa.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/pnm2ppa.conf.sample ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.post.mk>
