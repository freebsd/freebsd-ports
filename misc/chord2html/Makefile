# Created by: ijliao
# $FreeBSD$

PORTNAME=	chord2html
PORTVERSION=	1.3
PORTREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	http://T32.TecNik93.com/FreeBSD/ports/${PORTNAME}/sources/

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	Convert CHORD input files to HTML

RUN_DEPENDS=	p5-GD>=0:${PORTSDIR}/graphics/p5-GD

USE_PERL5=	yes
NO_BUILD=	yes
USES=		shebangfix
SHEBANG_FILES=	chord2html

MAN1=	chord2html.1

PLIST_FILES=	bin/chord2html share/chord2html/chord2html.css
PLIST_DIRS=	share/chord2html

post-patch:
	@${REINPLACE_CMD} -i '' -e "s,%%PREFIX%%,${PREFIX},g ; \
			 s,chord2html.css,${PREFIX}/share/chord2html/chord2html.css," \
		${WRKSRC}/chord2html

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/chord2html ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/chord2html.css ${DATADIR}

.include <bsd.port.mk>
