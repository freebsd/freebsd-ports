# New ports collection makefile for:	xspread
# Date created:		28 June 1995
# Whom:			janek@gaja.ipan.lublin.pl
#
# $FreeBSD$
#

PORTNAME=	xspread
PORTVERSION=	3.1.1c
CATEGORIES=	math
MASTER_SITES=	http://linux.tucows.com/files/x11/office/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LIBS="-L${X11BASE}/lib"

INSTALL_TARGET=	install install.man
MAN1=		xspread.1 pxspread.1

XS_DIR=		${PREFIX}/share/xspread

post-extract:
.for file in config.cache config.h config.log config.status
	@${RM} ${WRKSRC}/${file} || ${TRUE}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@find ${WRKSRC} -name "*.tmp" -delete || ${TRUE}
	@${MKDIR} ${XS_DIR}
	@${MKDIR} ${XS_DIR}/doc
	@${MKDIR} ${XS_DIR}/documents
	@${MKDIR} ${XS_DIR}/sample_files
	@${MKDIR} ${XS_DIR}/tests
	${INSTALL_DATA} ${WRKSRC}/README ${XS_DIR}
	${INSTALL_DATA} ${WRKSRC}/x/notes ${XS_DIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${XS_DIR}/doc
	${INSTALL_DATA} ${WRKSRC}/documents/* ${XS_DIR}/documents
	${INSTALL_DATA} ${WRKSRC}/sample_files/* ${XS_DIR}/sample_files
	${INSTALL_DATA} ${WRKSRC}/tests/* ${XS_DIR}/tests
.endif

.include <bsd.port.mk>
