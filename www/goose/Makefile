# Created by: ijliao
# $FreeBSD$

PORTNAME=	goose
PORTVERSION=	0.5
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}-search/${PORTNAME}-search/${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command line Google search utility

RUN_DEPENDS=	p5-SOAP-Lite>=0:net/p5-SOAP-Lite \
		p5-HTML-Tree>=0:www/p5-HTML-Tree \
		p5-HTML-Format>=0:textproc/p5-HTML-Format \
		p5-AppConfig>=0:devel/p5-AppConfig \
		p5-Curses>=0:devel/p5-Curses \
		urlview:textproc/urlview

USES=		perl5
WRKSRC=		${WRKDIR}/${PORTNAME}
POD2MAN?=	pod2man

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		-e "s|%%DATADIR%%|${DATADIR}|g" \
		-e "s|%%EXAMPLESDIR%%|${EXAMPLESDIR}|g" \
		-e "s|/usr/local/bin/url_handler.sh|${LOCALBASE}/urlview|" \
		${WRKSRC}/goose

do-build:
	cd ${WRKSRC} && ${POD2MAN} goose > goose.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/goose ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/GoogleSearch.wsdl ${STAGEDIR}${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/goose.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/goose.conf.example ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
