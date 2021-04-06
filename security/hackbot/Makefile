# Created by: mich@freebsdcluster.org

PORTNAME=	hackbot
PORTVERSION=	2.21
CATEGORIES=	security
MASTER_SITES=	http://freebsdcluster.org/~mich/software/ \
		http://hackbot.stream-portal.org/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Host exploration tool and bannergrabber

USES=		perl5 shebangfix tar:tgz
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

SHEBANG_FILES=	hackbot.pl

pre-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/etc|${DATADIR}|' ${WRKSRC}/hackbot.pl

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/google.db ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/fingerprint.db ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/cgi.db ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/hackbot.pl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/hackbot.1.gz ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
