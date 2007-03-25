# New ports collection makefile for:    hunspell
# Date created:         24.07.2004
# Whom:                 janos.mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	hunspell
PORTVERSION=	1.1.4
CATEGORIES=	hungarian textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}${PORTNAME}/:code \
		http://magyarispell.sourceforge.net/:data
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:code hu_HU-pack.zip:data

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Improved Hungarian spelling checker

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

BROKEN=		Does not install

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	"--with-ui"

MAN1=		hunspell.1
MAN4=		hunspell.4

PORTDOCS=	README README.myspell

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not compile on FreeBSD-4.x at this time
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/src/tools/hunspell.cxx

do-install:
	${INSTALL_MAN} ${WRKSRC}/man/hunspell.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/hunspell.4 ${PREFIX}/man/man4
	${INSTALL_PROGRAM} ${WRKSRC}/src/tools/hunspell ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/myspell/ && \
	${INSTALL_DATA} ${WRKDIR}/hu_HU.dic \
	${PREFIX}/share/myspell/ && \
	${INSTALL_DATA} ${WRKDIR}/hu_HU.aff \
	${PREFIX}/share/myspell/
	${LN} -s ${LOCALBASE}/share/myspell/hu_HU.dic ${PREFIX}/share/myspell/magyar.dic
	${LN} -s ${LOCALBASE}/share/myspell/hu_HU.dic ${PREFIX}/share/myspell/hungarian.dic
	${LN} -s ${LOCALBASE}/share/myspell/hu_HU.dic ${PREFIX}/share/myspell/default.dic
	${LN} -s ${LOCALBASE}/share/myspell/hu_HU.aff ${PREFIX}/share/myspell/magyar.aff
	${LN} -s ${LOCALBASE}/share/myspell/hu_HU.aff ${PREFIX}/share/myspell/hungarian.aff
	${LN} -s ${LOCALBASE}/share/myspell/hu_HU.aff ${PREFIX}/share/myspell/default.aff
	#${LOCALBASE}/bin/msgfmt -o ${WRKSRC}/hunspell.mo ${WRKSRC}/hunspell.po
	#${MKDIR} ${PREFIX}/share/locale/hu/LC_MESSAGES/ && \
	#${INSTALL_DATA} ${WRKSRC}/hunspell.mo ${PREFIX}/share/locale/hu/LC_MESSAGES/

.ifndef(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
