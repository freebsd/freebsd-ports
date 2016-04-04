# Created by: Jean-Yves Lefort <jylefort@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	7

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gtkmm-2.0.pc:x11-toolkits/gtkmm20

USES=		gmake pkgconfig
GNU_CONFIGURE=	yes

DOCSDIR=	${PREFIX}/share/doc/gtkmm-2.0

post-patch:
	@${FIND} ${WRKSRC}/examples -name Makefile.in \
		| ${XARGS} ${REINPLACE_CMD} -e '/^install-am:/ s| all-am||'

do-install:
.for d in docs examples
	@cd ${WRKSRC}/${d} && ${MAKE_CMD} ${MAKE_ARGS} install
.endfor

.include "${.CURDIR}/../../devel/glib20-reference/bsd.gnome-reference.mk"
