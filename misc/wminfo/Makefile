# Created by: Thomas Kempka <t.kempka@web.de>
# $FreeBSD$

PORTNAME=	wminfo
PORTVERSION=	1.51
PORTREVISION=	1
CATEGORIES=	misc windowmaker
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	pav

MAINTAINER=	t.kempka@web.de
COMMENT=	Dockapp to run shell scripts and display the output

WRKSRC=		${WRKDIR}/${PORTNAME}/${PORTNAME}

USE_XORG=	xpm

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|$$(LIBS)$$|& $$(OBJS)|g' \
		-e 's|/usr/X11R6|$$(LOCALBASE)|g' \
		-e 's|/share/include|/include|g' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wminfo ${PREFIX}/bin

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 900007
BROKEN=		fails to build with new utmpx
.endif

.include <bsd.port.post.mk>
