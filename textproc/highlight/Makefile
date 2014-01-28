# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	highlight
PORTVERSION=	2.16
PORTEPOCH=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.andre-simon.de/zip/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Customizable syntax highlighter

USES=	gmake
MAKEFILE=	makefile
MAKE_ARGS=	CXX="${CXX}" \
		CFLAGS="${CXXFLAGS} ${CPPFLAGS} -DHAVE_DECL_GETOPT" \
		LDFLAGS="${LDFLAGS}"

PORTDOCS=	ChangeLog INSTALL README README_DE \
		README_LANGLIST README_REGEX TODO
PORTEXAMPLES=	*

post-patch:
	@${REINPLACE_CMD} \
		-e 's|^PREFIX =|PREFIX ?=|' \
		-e 's|^conf_dir =.*|conf_dir = $${PREFIX}/etc/highlight/|' \
		${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e 's|^CXX=|CXX?=|' ${WRKSRC}/src/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1.gz ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/filetypes.conf ${STAGEDIR}${ETCDIR}/filetypes.conf.sample
.for d in langDefs themes
	@${MKDIR} ${STAGEDIR}${DATADIR}/$d
	cd ${WRKSRC} && ${COPYTREE_SHARE} $d ${STAGEDIR}${DATADIR}/$d
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
