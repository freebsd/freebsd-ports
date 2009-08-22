# New ports collection makefile for:	disktype
# Date created:				15 June 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	disktype
PORTVERSION=	9
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Disk formatting type autodetector

USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/disktype
PORTDOCS=	README

post-patch:
.for var in CFLAGS LDFLAGS CC
	@${REINPLACE_CMD} -e 's|^\(${var}\)[ ]*=|\1 ?=|' \
		${WRKSRC}/Makefile
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
