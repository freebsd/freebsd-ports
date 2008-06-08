# New ports collection makefile for:	wmcpuload
# Date created:				18 Apr 2001
# Whom:					Soeren Boll Overgaard <boll@tolkien.dk>
#
# $FreeBSD$
#

PORTNAME=	wmcpuload
PORTVERSION=	1.0.1
PORTREVISION=	4
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://seiichisato.jp/dockapps/src/

MAINTAINER=	xride@FreeBSD.org
COMMENT=	An "lcd" dockapp for windowmaker, which displays the current cpuload

USE_BZIP2=	yes
USE_XORG=	xpm
USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes

MAN1=		wmcpuload.1
PORTDOCS=	ChangeLog README
PLIST_FILES=	bin/wmcpuload

post-patch:
	@${REINPLACE_CMD} -e '/^DEFS/s|-I\.\.$$|-I.. -I../libdockapp/|g ; \
		 /^CFLAGS/s|-I../libdockapp/||g' ${WRKSRC}/src/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif # !NOPORTDOCS

.include <bsd.port.mk>
