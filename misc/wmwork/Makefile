PORTNAME=	wmwork
PORTVERSION=	0.2.5
PORTREVISION=	3
CATEGORIES=	misc windowmaker afterstep
MASTER_SITES=	http://people.debian.org/~godisch/wmwork/ \
		LOCAL/xride

MAINTAINER=	xride@FreeBSD.org
COMMENT=	Dockapp that keeps track of time you have spent on something

LICENSE=	GPLv2

USES=		gmake localbase xorg
USE_XORG=	x11 xext xpm
GNU_CONFIGURE=	yes
WRKSRC_SUBDIR=	src

PLIST_FILES=	bin/wmwork man/man1/wmwork.1.gz
PORTDOCS=	CHANGES README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmwork ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmwork.1 ${STAGEDIR}${MANPREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/../,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
