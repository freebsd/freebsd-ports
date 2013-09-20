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

RUN_DEPENDS=	p5-SOAP-Lite>=0:${PORTSDIR}/net/p5-SOAP-Lite \
		p5-HTML-Tree>=0:${PORTSDIR}/www/p5-HTML-Tree \
		p5-HTML-Format>=0:${PORTSDIR}/textproc/p5-HTML-Format \
		p5-AppConfig>=0:${PORTSDIR}/devel/p5-AppConfig \
		p5-Curses>=0:${PORTSDIR}/devel/p5-Curses \
		urlview:${PORTSDIR}/textproc/urlview

USES=		perl5
WRKSRC=		${WRKDIR}/${PORTNAME}
POD2MAN?=	pod2man

MAN1=	goose.1

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		-e "s|%%DATADIR%%|${DATADIR}|g" \
		-e "s|%%EXAMPLESDIR%%|${EXAMPLESDIR}|g" \
		-e "s|/usr/local/bin/url_handler.sh|${LOCALBASE}/urlview|" \
		${WRKSRC}/goose

do-build:
	@cd ${WRKSRC} && ${POD2MAN} goose > goose.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/goose ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/GoogleSearch.wsdl ${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/goose.1 ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/goose.conf.example ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
