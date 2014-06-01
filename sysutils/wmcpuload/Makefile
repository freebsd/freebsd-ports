# Created by: Soeren Boll Overgaard <boll@tolkien.dk>
# $FreeBSD$

PORTNAME=	wmcpuload
PORTVERSION=	1.0.1
PORTREVISION=	4
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://seiichisato.jp/dockapps/src/

MAINTAINER=	xride@FreeBSD.org
COMMENT=	An "lcd" dockapp for windowmaker, which displays the current cpuload

USES=		tar:bzip2
USE_XORG=	xpm
GNU_CONFIGURE=	yes

PORTDOCS=	ChangeLog README
PLIST_FILES=	bin/wmcpuload \
		man/man1/wmcpuload.1.gz

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/^DEFS/s|-I\.\.$$|-I.. -I../libdockapp/|g ; \
		 /^CFLAGS/s|-I../libdockapp/||g' ${WRKSRC}/src/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
