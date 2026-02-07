PORTNAME=	wmtop
DISTVERSION=	0.85
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	https://www.dockapps.net/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dockapp to display top three CPU consuming processes
WWW=		https://www.dockapps.net/wmtop

LICENSE=	GPLv2

LIB_DEPENDS=	libdockapp.so:x11-wm/libdockapp

USES=		autoreconf pkgconfig xorg
USE_CSTD=	gnu89
USE_XORG=	x11 xext xpm

GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/dockapps-be3f170

PLIST_FILES=	bin/wmtop \
		share/man/man1/wmtop.1.gz
PORTDOCS=	BUGS ChangeLog README TODO

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's/^\(LIBS.*\)/\1 -lkvm/ ; \
		s/^\(AM_CFLAGS.*\)/\1 -DNO_PROCFS/' ${WRKSRC}/Makefile.am

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmtop ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmtop.1 ${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
