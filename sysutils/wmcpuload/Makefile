PORTNAME=	wmcpuload
DISTVERSION=	1.1.1

CATEGORIES=	sysutils windowmaker
MASTER_SITES=	https://www.dockapps.net/download/

MAINTAINER=	drtr0jan@yandex.ru
COMMENT=	"lcd" dockapp for windowmaker, which displays the current cpuload
LICENSE=	GPLv2

USES=		xorg
USE_XORG+=	x11 xext xpm
GNU_CONFIGURE=	yes

PORTDOCS=	ChangeLog README
PLIST_FILES=	"@(,kmem,2555) bin/wmcpuload" \
		man/man1/wmcpuload.1.gz

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} '/SETGID_FLAGS=/d' ${WRKSRC}/configure

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
