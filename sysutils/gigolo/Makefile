# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gigolo
PORTVERSION=	0.4.90
CATEGORIES=	sysutils
MASTER_SITES=	XFCE/src/apps/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	koalative@gmail.com
COMMENT=	Frontend to easily manage filesystem connections

LICENSE=	GPLv2

ONLY_FOR_ARCHS=		amd64 i386 powerpc powerpc64 powerpcspe
ONLY_FOR_ARCHS_REASON=	Does not compile

BUILD_DEPENDS=	p5-XML-Parser>=0:textproc/p5-XML-Parser

USES=		gmake fuse pkgconfig gettext-tools xfce:gtk3 tar:bzip2
USE_GNOME=	cairo gdkpixbuf2 gtk30 gvfs intlhack
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
