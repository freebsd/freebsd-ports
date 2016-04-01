# Created by: Jean-Yves Lefort <jylefort@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	0

BUILD_DEPENDS=	${NONEXISTENT}:textproc/libxslt:configure

PARENT_WRKSRC!=	cd ${.CURDIR}/../libxslt && ${MAKE} -V WRKSRC
EXTRACT_ONLY=
USES=		gmake

do-install:
	@cd ${PARENT_WRKSRC}/doc && ${MAKE_CMD} ${MAKE_ARGS} install-data-local

.include "${.CURDIR}/../../devel/glib20-reference/bsd.gnome-reference.mk"
