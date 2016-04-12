# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gigolo
PORTVERSION=	0.4.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	XFCE/src/apps/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	koalative@gmail.com
COMMENT=	Frontend to easily manage filesystem connections

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-XML-Parser>=0:textproc/p5-XML-Parser

USES=		gmake fuse pkgconfig gettext-tools xfce tar:bzip2
USE_GNOME=	cairo gtk20 gvfs intlhack
USE_XORG=	x11
GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS ChangeLog NEWS README

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext-runtime

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	Does not compile

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
