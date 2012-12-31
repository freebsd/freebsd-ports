# Created by: corky1951@comcast.net
# $FreeBSD$

PORTNAME=	xsw
PORTVERSION=	0.3.5
PORTREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	A tool for creating presentations

RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick

USE_SDL=	sdl ttf image gfx

GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.if !defined(NO_INSTALL_MANPAGES)
MAN1=		xsw.1 \
		xsw2pdf.1 \
		xswconv.1

MANCOMPRESSED=	no
.endif

DOCS=		AUTHORS \
		COPYING \
		NEWS \
		README \
		REFERENCE \
		THANKS \
		TODO \
		doc/xsw.vim

.include <bsd.port.options.mk>

do-install:
	(cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} install)
	(cd ${WRKSRC}/data && ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} install)
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/$f ${DOCSDIR}
.endfor
.endif

.if !defined(NO_INSTALL_MANPAGES)
.for manpage in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/man/man1/${manpage} ${MAN1PREFIX}/man/man1
.endfor
.endif

.include <bsd.port.mk>
