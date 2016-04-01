# Created by: ijliao
# $FreeBSD$

PORTNAME=	chord2html
PORTVERSION=	1.3
PORTREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	http://T32.TecNik93.com/FreeBSD/ports/${PORTNAME}/sources/

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	Convert CHORD input files to HTML

RUN_DEPENDS=	p5-GD>=0:graphics/p5-GD

USES=		shebangfix perl5
NO_BUILD=	yes
SHEBANG_FILES=	chord2html

PLIST_FILES=	bin/chord2html share/chord2html/chord2html.css man/man1/chord2html.1.gz

post-patch:
	@${REINPLACE_CMD} -i '' -e "s,%%PREFIX%%,${PREFIX},g ; \
			 s,chord2html.css,${PREFIX}/share/chord2html/chord2html.css," \
		${WRKSRC}/chord2html

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/chord2html ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/chord2html.css ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
