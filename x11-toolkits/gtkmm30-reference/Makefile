# $FreeBSD$

PATCH_DEPENDS=	${NONEXISTENT}:${.CURDIR}/../gtk--2:patch
BUILD_DEPENDS=	${NONEXISTENT}:${.CURDIR}/../gtk--2:configure

PARENT_WRKSRC!=	cd ${.CURDIR}/../gtk--2 && ${MAKE} -V WRKSRC
EXTRACT_ONLY=
USE_GMAKE=	yes

DOCSDIR=	${PREFIX}/share/doc/gtkmm-2.0

post-patch:
	@${FIND} ${PARENT_WRKSRC}/examples -name Makefile.in \
		| ${XARGS} ${REINPLACE_CMD} -e '/^install-am:/ s| all-am||'

do-install:
.for d in docs examples
	@cd ${PARENT_WRKSRC}/${d} && ${GMAKE} install
.endfor

.include "${.CURDIR}/../../devel/glib20-reference/bsd.gnome-reference.mk"
