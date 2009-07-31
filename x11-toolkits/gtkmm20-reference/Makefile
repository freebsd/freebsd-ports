# New ports collection makefile for:	gtkmm20-reference
# Date created:				09 May 2006
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	4

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gtkmm-2.0.pc:${PORTSDIR}/x11-toolkits/gtkmm20

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

DOCSDIR=	${PREFIX}/share/doc/gtkmm-2.0

post-patch:
	@${FIND} ${WRKSRC}/examples -name Makefile.in \
		| ${XARGS} ${REINPLACE_CMD} -e '/^install-am:/ s| all-am||'

do-install:
.if !defined(NOPORTDOCS)
.for d in docs examples
	@cd ${WRKSRC}/${d} && ${GMAKE} install
.endfor
.endif

.include "${.CURDIR}/../../devel/glib20-reference/bsd.gnome-reference.mk"
