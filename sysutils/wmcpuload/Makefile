# Created by: Soeren Boll Overgaard <boll@tolkien.dk>
# $FreeBSD$

PORTNAME=	wmcpuload
PORTVERSION=	1.0.1
PORTREVISION=	4
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://seiichisato.jp/dockapps/src/

MAINTAINER=	xride@FreeBSD.org
COMMENT=	"lcd" dockapp for windowmaker, which displays the current cpuload

BROKEN=		unfetchable

USES=		tar:bzip2 xorg
USE_XORG=	xpm
GNU_CONFIGURE=	yes

PORTDOCS=	ChangeLog README
PLIST_FILES=	"@(,kmem,2555) bin/wmcpuload" \
		man/man1/wmcpuload.1.gz

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/^DEFS/s|-I\.\.$$|-I.. -I../libdockapp/|g ; \
		 /^CFLAGS/s|-I../libdockapp/||g' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} '/SETGID_FLAGS=/d' ${WRKSRC}/configure

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
