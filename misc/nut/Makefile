# New ports collection makefile for:	nut
# Date created:		Tue Apr 29 12:45:30 GMT 2003
# Whom:			Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	nut
PORTVERSION=	17.10
CATEGORIES=	misc
MASTER_SITES=	SF
PKGNAMEPREFIX=	health-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Nutrition software to record what you eat

LICENSE=	GPLv2 # (or later)
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DOCSDIR=	${PREFIX}/share/doc/${UNIQUENAME}
PORTDOCS=	CREDITS README nut.html
.endif

MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/${PORTNAME} %%DATADIR%%/FOOD_DES.txt \
		%%DATADIR%%/NUT_DATA.txt %%DATADIR%%/WEIGHT.lib \
		%%DATADIR%%/WEIGHT.txt %%DATADIR%%/sr24.nut
PLIST_DIRS=	%%DATADIR%%

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile" | ${XARGS} ${REINPLACE_CMD} -e \
		's|$$(prefix)/lib/nut|${DATADIR}| ; \
		 s|^CC =|CC ?=| ; \
		 s|^CXX =|CXX ?=| ; \
		 s|^CFLAGS :=|CFLAGS +=| ; \
		 s| -O | | ; \
		 s|ldstaticflags|ldflags| '

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${DATADIR}
	@(cd ${WRKSRC}/raw.data && ${COPYTREE_SHARE} . ${DATADIR})
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
