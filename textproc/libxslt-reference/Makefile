# New ports collection makefile for:	libxslt-reference
# Date created:				09 May 2006
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	0

BUILD_DEPENDS=	${NONEXISTENT}:${.CURDIR}/../libxslt:configure

PARENT_WRKSRC!=	cd ${.CURDIR}/../libxslt && ${MAKE} -V WRKSRC
EXTRACT_ONLY=
USE_GMAKE=	yes

do-install:
.if !defined(NOPORTDOCS)
	@cd ${PARENT_WRKSRC}/doc && ${GMAKE} install-data-local
.endif

.include "${.CURDIR}/../../devel/glib20-reference/bsd.gnome-reference.mk"
