# New ports collection makefile for:	xspread
# Date created:		28 June 1995
# Whom:			janek@gaja.ipan.lublin.pl
#
# $FreeBSD$
#

PORTNAME=	xspread
PORTVERSION=	3.1.1c
CATEGORIES=	math
MASTER_SITES=	# disappeared
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A spreadsheet program for X and terminals

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.orig

USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LIBS="-L${X11BASE}/lib"

MAN1=		xspread.1 pxspread.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pxspread ${PREFIX}/bin/pxspread
	${INSTALL_PROGRAM} ${WRKSRC}/xspread ${PREFIX}/bin/xspread
	${INSTALL_MAN} ${WRKSRC}/pxspread.man ${MANPREFIX}/man/man1/pxspread.1
	${INSTALL_MAN} ${WRKSRC}/xspread.man ${MANPREFIX}/man/man1/xspread.1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/x/notes ${DOCSDIR}
.for dir in doc documents sample_files tests
	@${TAR} -C ${WRKSRC} --exclude '*.tmp' -cf - ${dir} | \
		${TAR} -C ${DOCSDIR} --unlink -xf -
.endfor
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.mk>
