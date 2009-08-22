# New ports collection makefile for:    kmflcomp
# Date created:		10 October 2007
# Whom:			Nikola Lecic <nikola.lecic@anthesphoria.net>
#
# $FreeBSD$
#

PORTNAME=	kmflcomp
PORTVERSION=	0.9.8
CATEGORIES=	textproc
MASTER_SITES=	SF/kmfl/kmfl/${PORTVERSION} \
		http://anthesphoria.net/FreeBSD/ports/distfiles/

DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz \
		KMFL-Compiler.sxw
DIST_SUBDIR=	kmfl
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}.tar.gz

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	Compiler of Keyman keyboard sources to use with SCIM KMFL IMEngine

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison

USE_XORG=	x11
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl"

DOCSDIR=	${PREFIX}/share/doc/kmfl/${PORTNAME}
DOCS=		${DISTDIR}/${DIST_SUBDIR}/KMFL-Compiler.sxw \
		${WRKSRC}/AUTHORS \
		${WRKSRC}/COPYING \
		${WRKSRC}/ChangeLog

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|^install-data-am: install-kmflcompdocDATA|install-data-am:|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|-L/usr/X11R6/lib|-L${X11BASE}/lib|' \
		${WRKSRC}/kmfl_compiler/Makefile.in
	@${REINPLACE_CMD} -E 's,"UTF(8|16LE|32LE)","UTF-\1",g' \
		${WRKSRC}/src/utfconv.c
	@${REINPLACE_CMD} -E 's,(VERSION= *)"0\.9\.7",\1"0.9.8",' \
		${WRKSRC}/kmfl_compiler/kmfl_compiler.c

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} -v ${DOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
