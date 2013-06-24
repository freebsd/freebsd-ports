# Created by: Cyrille Lefevre <clefevre@citeweb.net>
# $FreeBSD$

PORTNAME=	sed
PORTVERSION=	4.2.2
CATEGORIES=	textproc
MASTER_SITES=	GNU
PKGNAMEPREFIX=	g

MAINTAINER=	johans@FreeBSD.org
COMMENT=	The GNU stream editor

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	MAKEINFO="makeinfo --no-split"

USES=		charsetfix
PATCH_SUBDIRS=	. doc lib sed
DATADIR=	${PREFIX}/share/${PKGBASE}
SAMP_FILES=	binary*.sed dc.sed
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGBASE}
PORTDOCS=	AUTHORS BUGS COPYING COPYING.DOC NEWS README THANKS
DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}
USE_GMAKE=	yes
INFO=		sed
MAN1=		gsed.1

OPTIONS_DEFINE=	NLS DOCS

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext iconv
PLIST_SUB=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} 's,^\* sed:,* GNU sed:,' \
		${WRKSRC}/doc/config.texi
	@${REINPLACE_CMD} "s|#include <alloca.h>||" ${WRKSRC}/lib/regex_internal.h

post-configure:
.for subdir in ${PATCH_SUBDIRS}
	@${REINPLACE_CMD} -e 's|s,x,x,|s,^,g,|' \
			  -e 's|^doc_DATA|#doc_DATA|' \
		${WRKSRC}/${subdir}/Makefile
.endfor

post-install:
	@${MKDIR} ${EXAMPLESDIR}
.for f in ${SAMP_FILES}
	@${INSTALL_DATA} ${WRKSRC}/testsuite/${f} ${EXAMPLESDIR}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

# Maintainer only
test:
	@cd ${WRKSRC}/testsuite; ${MAKE} check

.include <bsd.port.post.mk>
