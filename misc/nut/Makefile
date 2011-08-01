# New ports collection makefile for:	nut
# Date created:		Tue Apr 29 12:45:30 GMT 2003
# Whom:			Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	nut
PORTVERSION=	16.13
CATEGORIES=	misc
MASTER_SITES=	SF
PKGNAMEPREFIX=	health-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nutrition software to record what you eat

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

OPTIONS=	GUI "Build FLTK-based GUI" off

USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

DOCSDIR=	${PREFIX}/share/doc/${UNIQUENAME}

MAN1=		${PORTNAME}.1
PORTDOCS=	CREDITS README nut.html
PLIST_FILES=	bin/${PORTNAME} %%DATADIR%%/FOOD_DES.txt \
		%%DATADIR%%/NUT_DATA.txt %%DATADIR%%/WEIGHT.lib \
		%%DATADIR%%/WEIGHT.txt %%DATADIR%%/sr23.nut
PLIST_DIRS=	%%DATADIR%%

.include <bsd.port.pre.mk>

.if defined(WITH_GUI)
LIB_DEPENDS+=	fltk.1:${PORTSDIR}/x11-toolkits/fltk
PLIST_FILES+=	bin/Nut
.else
EXTRA_PATCHES=	${FILESDIR}/extra-patch-Makefile
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile" | ${XARGS} ${REINPLACE_CMD} -e \
		's|$$(prefix)/lib/nut|${DATADIR}| ; \
		 s|^CC =|CC ?=| ; \
		 s|^CXX =|CXX ?=| ; \
		 s|^CFLAGS :=|CFLAGS +=| ; \
		 s| -O | |'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1
.if defined(WITH_GUI)
	${INSTALL_PROGRAM} ${WRKSRC}/fltk/Nut ${PREFIX}/bin
.endif
	@${MKDIR} ${DATADIR}
	@(cd ${WRKSRC}/raw.data && ${COPYTREE_SHARE} . ${DATADIR})
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
