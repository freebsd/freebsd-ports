# ports collection makefile for:	xmbmon
# Date created:	2001/08/30
# Whom:		kaz
#
# $FreeBSD$
#

PORTNAME=	xmbmon
PORTVERSION=	107p1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.nt.phys.kyushu-u.ac.jp/shimizu/download/
DISTNAME=	${PORTNAME}${PORTVERSION:S/p/pl/}

MAINTAINER=	kaz@kobe1995.net

GNU_CONFIGURE=	yes
DOCS=	00README.txt	00READMEj.txt	DEBUG_Info	xmbmon.resources

WITHOUT_X11?= no

.if (${WITHOUT_X11} == yes)
MAKE_ARGS+=	WITHOUT_X11=yes DOCSDIR='$(DOCSDIR)' INSTALL_DATA='$(INSTALL_DATA)'
DOCS=   	00README.txt    00READMEj.txt   DEBUG_Info
PLIST_SUB=	X11_ONLY="@comment "
.else
USE_XLIB=	yes
MAKE_ARGS+=	DOCSDIR='$(DOCSDIR)' INSTALL_DATA='$(INSTALL_DATA)'
PLIST_SUB=	X11_ONLY=""
.endif

.include <bsd.port.pre.mk>

pre-extract:
	@${ECHO}
	@${ECHO} "set WITHOUT_X11 variable to 'yes' if you want to build without X11"
	@${ECHO}

post-patch:
	@${MV} -f ${WRKSRC}/Makefile.in ${WRKSRC}/Makefile.in.X
.if ${WITHOUT_X11} == yes
	@${GREP} -v '^PROGRAM+=' ${WRKSRC}/Makefile.in.X | ${SED} 's/__DOCS__/$(DOCS)/' > ${WRKSRC}/Makefile.in
.else
	@${SED} 's/__DOCS__/$(DOCS)/' ${WRKSRC}/Makefile.in.X > ${WRKSRC}/Makefile.in
.endif
	@${RM} -f ${WRKSRC}/Makefile.in.X

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}; ${MAKE} ${MAKE_ARGS} install-doc)
.endif

.include <bsd.port.post.mk>
