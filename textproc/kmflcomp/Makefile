# Created by: Nikola Lecic <nikola.lecic@anthesphoria.net>
# $FreeBSD$

PORTNAME=	kmflcomp
PORTVERSION=	0.9.9
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	SF/kmfl/kmfl/${PORTVERSION}:1 \
		SF/kmfl/kmfl/Documentation:2 \
		http://anthesphoria.net/FreeBSD/ports/distfiles/${DIST_SUBDIR}/:1,2
DISTFILES=	${DISTNAME}.tar.gz:1 \
		KMFL-Compiler.sxw:2
DIST_SUBDIR=	kmfl
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	Compiler of Keyman KMFL keyboard sources to use with SCIM/IBus

BUILD_DEPENDS=	bison:devel/bison

USE_XORG=	x11
USE_LDCONFIG=	yes
USES=		iconv libtool
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS
DOCSDIR=	${PREFIX}/share/doc/kmfl/${PORTNAME}
DOCS=		${DISTDIR}/${DIST_SUBDIR}/KMFL-Compiler.sxw \
		${WRKSRC}/AUTHORS \
		${WRKSRC}/COPYING \
		${WRKSRC}/ChangeLog

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|^install-data-am: install-kmflcompdocDATA|install-data-am:|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|-L/usr/X11R6/lib|-L${LOCALBASE}/lib|' \
		${WRKSRC}/kmfl_compiler/Makefile.in
	@${REINPLACE_CMD} -E 's,(VERSION= *)"0\.9\.7",\1"0.9.9",' \
		${WRKSRC}/kmfl_compiler/kmfl_compiler.c

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} -v ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
