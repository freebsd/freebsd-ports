# $FreeBSD$

BUILD_DEPENDS=	${NONEXISTENT}:${.CURDIR}/../libxml2:configure

PARENT_WRKSRC!=	cd ${.CURDIR}/../libxml2 && ${MAKE} -V WRKSRC
EXTRACT_ONLY=
USE_GMAKE=	yes

EXAMPLES=	testHTML.c testSAX.c testXPath.c xmllint.c
PLIST_FILES=	${EXAMPLES:S|^|%%EXAMPLESDIR%%/|}
PLIST_DIRS=	%%EXAMPLESDIR%%

do-install:
.for d in . doc doc/devhelp doc/examples
	@cd ${PARENT_WRKSRC}/${d} && ${GMAKE} install-data-local
.endfor

.include "${.CURDIR}/../../devel/glib20-reference/bsd.gnome-reference.mk"
