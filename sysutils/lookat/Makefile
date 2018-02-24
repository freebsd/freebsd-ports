# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	lookat
PORTVERSION=	1.4.4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.wagemakers.be/downloads/lookat/
DISTNAME=	${PORTNAME}_bekijk-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program to view Un*x text files and manual pages

GNU_CONFIGURE=	yes
USES=		gmake ncurses

PLIST_FILES=	bin/lookat \
		"@sample etc/lookat.conf.sample" \
		man/man1/lookat.1.gz
PORTDOCS=	README
PORTEXAMPLES=	blue_config.cfg

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} 's|/etc/lookat.conf|${PREFIX}&|g' \
		${WRKSRC}/${PORTNAME}.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lookat ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/lookat.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/lookat.conf.default \
		${STAGEDIR}${PREFIX}/etc/lookat.conf.sample

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/blue_config.cfg \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
