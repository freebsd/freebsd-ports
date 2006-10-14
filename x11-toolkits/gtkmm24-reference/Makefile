# New ports collection makefile for:	gtkmm24-reference
# Date created:				09 May 2006
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	2

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gtkmm-2.4.pc:${PORTSDIR}/x11-toolkits/gtkmm24

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

DOCSDIR=	${PREFIX}/share/doc/gtkmm-2.4

post-patch:
	@${FIND} ${WRKSRC}/examples -name Makefile.in \
		| ${XARGS} ${REINPLACE_CMD} -e '/^install-am:/ s| all-am||'

do-install:
.for d in docs examples
	@cd ${WRKSRC}/${d} && ${GMAKE} install
.endfor

.include "${.CURDIR}/../../devel/glib20-reference/bsd.gnome-reference.mk"
