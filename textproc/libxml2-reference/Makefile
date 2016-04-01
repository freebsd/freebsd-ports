# Created by: Jean-Yves Lefort <jylefort@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	0

BUILD_DEPENDS=	${NONEXISTENT}:textproc/libxml2:configure

PARENT_WRKSRC!=	cd ${.CURDIR}/../libxml2 && ${MAKE} -V WRKSRC
EXTRACT_ONLY=
USES=		gmake
MAKE_ARGS=	DOC_MODULE=libxml2 EXAMPLES_DIR=${EXAMPLESDIR}

OPTIONS_DEFINE=	EXAMPLES

EXAMPLES=	testHTML.c testSAX.c testXPath.c xmllint.c
EXAMPLES_PLIST_FILES=	${EXAMPLES:S|^|%%EXAMPLESDIR%%/|}

do-install:
.for d in . doc doc/examples
	@cd ${PARENT_WRKSRC}/${d} && ${MAKE_CMD} ${MAKE_ARGS} install-data-local
.endfor

.include "${.CURDIR}/../../devel/glib20-reference/bsd.gnome-reference.mk"
