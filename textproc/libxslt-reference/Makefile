# $FreeBSD$

BUILD_DEPENDS=	${NONEXISTENT}:${.CURDIR}/../libxslt:configure

PARENT_WRKSRC!=	cd ${.CURDIR}/../libxslt && ${MAKE} -V WRKSRC
EXTRACT_ONLY=
USE_GMAKE=	yes

do-install:
	@cd ${PARENT_WRKSRC}/doc && ${GMAKE} install-data-local

.include "${.CURDIR}/../../devel/glib20-reference/bsd.gnome-reference.mk"
