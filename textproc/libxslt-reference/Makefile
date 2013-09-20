# Created by: Jean-Yves Lefort <jylefort@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	0

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/textproc/libxslt:configure

PARENT_WRKSRC!=	cd ${.CURDIR}/../libxslt && ${MAKE} -V WRKSRC
EXTRACT_ONLY=
USE_GMAKE=	yes

NO_STAGE=	yes
do-install:
.if !defined(NOPORTDOCS)
	@cd ${PARENT_WRKSRC}/doc && ${GMAKE} install-data-local
.endif

.include "${.CURDIR}/../../devel/glib20-reference/bsd.gnome-reference.mk"
