# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/textproc/libxml++26-reference/Makefile,v 1.1 2010/04/03 16:21:50 avl Exp $

PORTREVISION=	0

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/libxml++-2.6.pc:textproc/libxml++26 \
		glibmm-reference>=0:devel/glibmm-reference

USES=		gmake pkgconfig
GNU_CONFIGURE=	yes

BROKEN=		fails to stage

DOCSDIR=	${PREFIX}/share/doc/libxml++-2.6

do-install:
	@cd ${WRKSRC} && ${MAKE_CMD} ${MAKE_ARGS} install-data-local install-dist_referenceDATA

.include "${.CURDIR}/../../devel/glib20-reference/bsd.gnome-reference.mk"
