# Created by: Leland Wang <llwang@infor.org>
# $FreeBSD$

PORTNAME=	dvorak7min
PORTVERSION=	1.6.1
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ncurses-based Dvorak typing tutor

LICENSE=	GPLv2 # (or later)

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e \
		's|^\(PROF\)|#\1| ; \
		 /^CFLAGS/s|\([[:space:]]\)=|\1+=| ; \
		 s|^\(LDFLAGS\)|#\1| ; \
		 s|-lncurses|-lcurses|' ${WRKSRC}/Makefile

pre-build:
	@${RM} -f ${WRKSRC}/*.o

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} dvorak7min \
		${STAGEDIR}${PREFIX}/bin)

.include <bsd.port.mk>
