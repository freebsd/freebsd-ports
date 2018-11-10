# Created by: Cyrille Lefevre <clefevre@citeweb.net>
# $FreeBSD$

PORTNAME=	sed
PORTVERSION=	4.2.2
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	GNU
PKGNAMEPREFIX=	g

MAINTAINER=	johans@FreeBSD.org
COMMENT=	The GNU stream editor

LICENSE=	GPLv3+ GFDL
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING
LICENSE_FILE_GFDL=	${WRKSRC}/COPYING.DOC

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	MAKEINFO="${MAKEINFO} --no-split"
TEST_TARGET=	check

USES=		charsetfix makeinfo gmake
PATCH_SUBDIRS=	. doc lib sed
DATADIR=	${PREFIX}/share/${PKGBASE}
SAMP_FILES=	binary*.sed dc.sed
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGBASE}
PORTDOCS=	AUTHORS BUGS NEWS README THANKS
DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}
INFO=		sed

OPTIONS_DEFINE=	NLS DOCS EXAMPLES
OPTIONS_SUB=	yes

NLS_USES=	gettext iconv
NLS_CONFIGURE_ENABLE=	nls

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
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ${SAMP_FILES}
	${INSTALL_DATA} ${WRKSRC}/testsuite/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
