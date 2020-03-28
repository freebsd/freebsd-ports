# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gigolo
PORTVERSION=	0.5.1
CATEGORIES=	sysutils
MASTER_SITES=	XFCE/apps

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Frontend to easily manage filesystem connections

LICENSE=	GPLv2

ONLY_FOR_ARCHS=         aarch64 amd64 armv6 armv7 i386 powerpc \
			powerpc64 powerpcspe
ONLY_FOR_ARCHS_REASON=	Does not compile

BUILD_DEPENDS=	p5-XML-Parser>=0:textproc/p5-XML-Parser

USES=		fuse gettext-tools gmake gnome pkgconfig tar:bzip2 xfce xorg
USE_GNOME=	cairo gdkpixbuf2 gtk30 gvfs intltool
USE_XORG=	x11

GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS ChangeLog NEWS README

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext-runtime

post-patch:
	@${REINPLACE_CMD} -e 's|^DOCFILES.*|DOCFILES =|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|$$(prefix)/$$(DATADIRNAME)/locale|$$(datarootdir)/locale|' \
		${WRKSRC}/po/Makefile.in.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
