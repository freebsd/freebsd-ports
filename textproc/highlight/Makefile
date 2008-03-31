# New ports collection makefile for:	highlight
# Date created:				05 August 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	highlight
PORTVERSION=	2.6.7
PORTEPOCH=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.andre-simon.de/zip/

MAINTAINER=	alexbl@FreeBSD.org
COMMENT=	Customizable syntax highlighter

USE_GMAKE=	yes
MAKEFILE=	makefile
MAKE_ARGS=	CXX="${CXX}" \
		CFLAGS="${CXXFLAGS} ${CPPFLAGS} -DHAVE_DECL_GETOPT" \
		LDFLAGS="${LDFLAGS}"

PLIST_FILES=	bin/highlight

MAN1=		${PORTNAME}.1
MANCOMPRESSED=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|^PREFIX =|PREFIX ?=|' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/${MAN1}.gz ${MANPREFIX}/man/man1
	@${MKDIR} ${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/filetypes.conf ${ETCDIR}
	@${MKDIR} ${DATADIR}/helpmsg
	${INSTALL_DATA} ${WRKSRC}/helpmsg/* ${DATADIR}/helpmsg
	@${MKDIR} ${DATADIR}/langDefs
	${INSTALL_DATA} ${WRKSRC}/langDefs/*.lang ${DATADIR}/langDefs
	@${MKDIR} ${DATADIR}/themes
	${INSTALL_DATA} ${WRKSRC}/themes/* ${DATADIR}/themes
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in AUTHORS ChangeLog INSTALL README README_DE README_ES README_INDENT \
	README_REGEX TODO
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
	@${MKDIR} ${EXAMPLESDIR}
	${TAR} -C ${WRKSRC}/examples -cf - . | \
		${TAR} -C  ${EXAMPLESDIR} --unlink -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

post-install:
.for dir in ${ETCDIR} ${DATADIR} ${EXAMPLESDIR}
	@${FIND} ${dir} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${dir} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.endfor

.include <bsd.port.post.mk>
