PORTNAME=	wmcpuload
DISTVERSION=	1.1.1
PORTREVISION=	1

CATEGORIES=	sysutils windowmaker
MASTER_SITES=	https://www.dockapps.net/download/

MAINTAINER=	drtr0jan@yandex.ru
COMMENT=	"lcd" dockapp for windowmaker, which displays the current cpuload
WWW=		https://www.dockapps.net/wmcpuload
LICENSE=	GPLv2

USES=		xorg
USE_XORG+=	x11 xext xpm
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PORTDOCS=	ChangeLog README
PLIST_FILES=	"@(,kmem,2555) bin/wmcpuload" \
		share/man/man1/wmcpuload.1.gz

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} '/SETGID_FLAGS=/d' ${WRKSRC}/configure

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
