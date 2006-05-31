# New ports collection makefile for:	gtkmm24-reference
# Date created:				09 May 2006
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	0

PATCH_DEPENDS=	${NONEXISTENT}:${.CURDIR}/../gtkmm24:patch
BUILD_DEPENDS=	${NONEXISTENT}:${.CURDIR}/../gtkmm24:configure

PARENT_WRKSRC!=	cd ${.CURDIR}/../gtkmm24 && ${MAKE} -V WRKSRC
EXTRACT_ONLY=
USE_GMAKE=	yes
PREFIX=		${X11BASE}

DOCSDIR=	${PREFIX}/share/doc/gtkmm-2.4

post-patch:
	@${FIND} ${PARENT_WRKSRC}/examples -name Makefile.in \
		| ${XARGS} ${REINPLACE_CMD} -e '/^install-am:/ s| all-am||'

do-install:
.for d in docs examples
	@cd ${PARENT_WRKSRC}/${d} && ${GMAKE} install
.endfor

.include "${.CURDIR}/../../devel/glib20-reference/bsd.gnome-reference.mk"
