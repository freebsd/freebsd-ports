# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gwhois
PORTVERSION=	20120626
CATEGORIES=	net
MASTER_SITES=	http://gwhois.de/gwhois/
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flexible whois client and proxy

RUN_DEPENDS=	p5-libwww>=5.805:${PORTSDIR}/www/p5-libwww \
		p5-Net-LibIDN>=0:${PORTSDIR}/dns/p5-Net-LibIDN \
		lynx:${PORTSDIR}/www/lynx \
		curl:${PORTSDIR}/ftp/curl

NO_BUILD=	yes
USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	gwhois
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
PLIST_FILES=	bin/${PORTNAME} man/man1/gwhois.1.gz %%DATADIR%%/pattern
PORTDOCS=	TODO README.RIPE

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e 's|/etc/gwhois|${DATADIR}|g'\
		${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/pattern ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
