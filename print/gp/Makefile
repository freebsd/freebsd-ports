# New ports collection makefile for: GP
# Version required:	2.5
# Date created:		15 April 1997
# Whom:			Kiriyama Kazuhiko<kiri@kiri.toba-cmt.ac.jp>
#
# $Id: Makefile,v 1.6 1998/06/04 18:28:10 itojun Exp $
#

DISTNAME=	GP-2.5
PKGNAME?=	gp-2.5
CATEGORIES+=	print tk42
MASTER_SITES=	http://www.kamome.or.jp/hueda/GP/ \
		ftp://www.neosoft.com/pub/tcl/sorted/print/GP-2.5/

MAINTAINER=	kiri@kiri.toba-cmt.ac.jp

LIB_DEPENDS=	${WITH_LIB}
RUN_DEPENDS=	${PREFIX}/bin/psbook:${PORTSDIR}/print/psutils \
		${X11BASE}/bin/gv:${PORTSDIR}/print/gv \
		${PREFIX}/bin/convert:${PORTSDIR}/graphics/ImageMagick \
		${WITH_RUN}

PATCHDIR=	${.CURDIR}/../../print/gp/patches
FILESDIR=	${.CURDIR}/../../print/gp/files
SCRIPTDIR=	${.CURDIR}/../../print/gp/scripts

LANGUAGE?=	English

.if (${LANGUAGE} == "Japanese")
ALL_TARGET=	ja filters
.else
ALL_TARGET=	filters
.endif
MAKE_ENV=	LANGUAGE=${LANGUAGE}
SCRIPTS_ENV=	MV=${MV} RM=${RM} SED=${SED} LANGUAGE=${LANGUAGE}

PORTDOCDIR=	${PREFIX}/share/doc/GP
.if (${LANGUAGE} == "Japanese")
DOCDIRNAME=	Doc.ja
DOCEXT=		.euc
WITH_LIB=	tcl76jp\\.1\\.:${PORTSDIR}/japanese/tcl76
WITH_RUN=	${PREFIX}/bin/wish4.2jp:${PORTSDIR}/japanese/tk42 \
		${PREFIX}/bin/a2ps-j:${PORTSDIR}/japanese/a2ps \
		${X11BASE}/bin/xdvi:${PORTSDIR}/japanese/vfxdvi \
		${PREFIX}/bin/dvi2ps:${PORTSDIR}/japanese/dvi2ps
.else
DOCDIRNAME=	Doc
DOCEXT=
WITH_LIB=	tcl76\\.1\\.:${PORTSDIR}/lang/tcl76
WITH_RUN=	${PREFIX}/bin/wish4.2:${PORTSDIR}/x11-toolkits/tk42 \
		${PREFIX}/bin/a2ps:${PORTSDIR}/print/a2ps \
		${X11BASE}/bin/xdvi:${PORTSDIR}/print/xdvi \
		${PREFIX}/bin/dvips:${PORTSDIR}/print/dvips
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PORTDOCDIR}/Manual/${LANGUAGE}/image
	@(cd ${WRKSRC}; \
	${INSTALL_DATA} ${DOCDIRNAME}/*${DOCEXT} ${PORTDOCDIR}; \
	)
	@(cd ${WRKSRC}/Manual; \
	${INSTALL_DATA} GP.gif README${DOCEXT} index.html ${PORTDOCDIR}/Manual; \
	${INSTALL_DATA} ${LANGUAGE}/*.html  ${PORTDOCDIR}/Manual/${LANGUAGE}; \
	${INSTALL_DATA} ${LANGUAGE}/image/*.gif  ${PORTDOCDIR}/Manual/${LANGUAGE}/image; \
	)
.endif

.include <bsd.port.mk>
