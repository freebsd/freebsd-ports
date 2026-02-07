PORTNAME=	kmfl-european-latin
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.tavultesoft.com/eurolatin/ \
		http://anthesphoria.net/FreeBSD/ports/distfiles/${DIST_SUBDIR}/
DISTNAME=	eurolatin-source-${PORTVERSION}
DIST_SUBDIR=	kmfl

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	Paneuropean Latin KMFL keyboard covering 120 languages
WWW=		http://eurolatin.keymankeyboards.com/

RUN_DEPENDS=	kmflcomp:textproc/kmflcomp

USES=		dos2unix zip
DOS2UNIX_FILES=	european.kmn

DOCSDIR=	${PREFIX}/share/doc/kmfl/${PORTNAME}
SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/EuroLatin\ Source\ Files

OPTIONS_DEFINE=	DOCS

DOCSLIST=	EuroLatin\ Keyman\ Desktop\ Keyboard\ Files/eurolatin1.6.pdf \
		EuroLatin\ KeymanWeb\ Keyboard\ Files/european.html \
		licence.txt
KMFL_DIR=	share/kmfl
KMFL_ICONS_DIR=	share/kmfl/icons

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400079
BASE64=	/usr/bin/base64
.else
BUILD_DEPENDS=	base64:converters/base64
BASE64=	${LOCALBASE}/bin/base64
.endif

do-build:
	${BASE64} -d ${FILESDIR}/latin.png.base64.txt > ${WRKSRC}/latin.png

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${KMFL_DIR} ${STAGEDIR}${PREFIX}/${KMFL_ICONS_DIR}
	${INSTALL_DATA} ${WRKSRC}/*.kmn ${STAGEDIR}${PREFIX}/${KMFL_DIR}
	${INSTALL_DATA} ${WRKSRC}/latin.png ${STAGEDIR}${PREFIX}/${KMFL_ICONS_DIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	for doc in ${DOCSLIST} ; do \
		${INSTALL_DATA} ${WRKSRC}/"$$doc" ${STAGEDIR}${DOCSDIR} ; \
	done

.include <bsd.port.post.mk>
