# New ports collection makefile for:	highlight
# Date created:				05 August 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	highlight
PORTVERSION=	2.16
PORTEPOCH=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.andre-simon.de/zip/

MAINTAINER=	yzlin@FreeBSD.org
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
PORTDOCS=	ChangeLog INSTALL README README_DE \
		README_LANGLIST README_REGEX TODO

.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} \
		-e 's|^PREFIX =|PREFIX ?=|' \
		-e 's|^conf_dir =.*|conf_dir = $${PREFIX}/etc/highlight/|' \
		${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e 's|^CXX=|CXX?=|' ${WRKSRC}/src/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/${MAN1}.gz ${MANPREFIX}/man/man1
	@${MKDIR} ${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/filetypes.conf ${ETCDIR}
.for d in langDefs themes
	@${MKDIR} ${DATADIR}/$d
	${INSTALL_DATA} ${WRKSRC}/$d/* ${DATADIR}/$d
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

post-install:
.for dir in ${ETCDIR} ${DATADIR} ${EXAMPLESDIR}
	@${FIND} ${dir} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${dir} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.endfor

.include <bsd.port.post.mk>
