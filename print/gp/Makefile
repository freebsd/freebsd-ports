# New ports collection makefile for: GP
# Date created:		15 April 1997
# Whom:			Kiriyama Kazuhiko<kiri@kiri.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	gp
PORTVERSION=	2.5.p2
CATEGORIES+=	print tk42
MASTER_SITES=	http://www.itbrain.co.jp/~ueda/GP/
DISTNAME=	GP-2.5p2	

MAINTAINER=	kiri@kiri.toba-cmt.ac.jp

PATCHDIR=	${.CURDIR}/../../print/gp/files
FILESDIR=	${.CURDIR}/../../print/gp/files
SCRIPTDIR=	${.CURDIR}/../../print/gp/scripts

RUN_DEPENDS=	${PREFIX}/bin/psbook:${PORTSDIR}/print/psutils-${PAPERSIZE} \
		${X11BASE}/bin/gv:${PORTSDIR}/print/gv \
		${PREFIX}/bin/convert:${PORTSDIR}/graphics/ImageMagick

LANGUAGE?=	English

.if (${LANGUAGE} == "English")
FORBIDDEN=	Broken unless someone makes it work with tcl/tk 8.X
ALL_TARGET=	filters
#LIB_DEPENDS=	tcl76.1:${PORTSDIR}/lang/tcl76
#RUN_DEPENDS+=	${PREFIX}/bin/wish4.2:${PORTSDIR}/x11-toolkits/tk42
LANGEXT=	en
DOCDIRNAME=	Doc
DOCEXT=
PAPERSIZE=	letter
.elif (${LANGUAGE} == "Japanese")
ALL_TARGET=	ja filters
LIB_DEPENDS=	tcl76jp.1:${PORTSDIR}/japanese/tcl76
RUN_DEPENDS+=	${PREFIX}/bin/wish4.2jp:${PORTSDIR}/japanese/tk42
LANGEXT=	ja
DOCDIRNAME=	Doc.ja
DOCEXT=		.euc
PAPERSIZE=	a4
.else
FORBIDDEN=	Broken unless someone makes it work with tcl/tk 8.X
PAPERSIZE=	a4
.endif
MAKE_ENV=	LANGUAGE=${LANGUAGE} LANGEXT=${LANGEXT}
SCRIPTS_ENV=	MV=${MV} RM=${RM} SED=${SED} LANGUAGE=${LANGUAGE} LANGEXT=${LANGEXT}

.if (${LANGEXT} == "en")
PORTDOCDIR=	${PREFIX}/share/doc/GP/
.else
PORTDOCDIR=	${PREFIX}/share/doc/GP/${LANGEXT}/
.endif

post-install:
	if [ -h ${PREFIX}/bin/GP ]; then \
		${MV} ${PREFIX}/bin/GP ${PREFIX}/bin/GP.previous; \
	fi
	${LN} -sf GP${LANGEXT} ${PREFIX}/bin/GP
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PORTDOCDIR}Manual/image
	@(cd ${WRKSRC}; \
	${INSTALL_DATA} ${DOCDIRNAME}/*${DOCEXT} ${PORTDOCDIR}; \
	)
	@(cd ${WRKSRC}/Manual; \
	${INSTALL_DATA} GP.gif README${DOCEXT} index.html ${PORTDOCDIR}Manual; \
	${INSTALL_DATA} ${LANGUAGE}/*.html  ${PORTDOCDIR}Manual; \
	${INSTALL_DATA} ${LANGUAGE}/image/*.gif  ${PORTDOCDIR}Manual/image; \
	)
.endif

.include <bsd.port.mk>
