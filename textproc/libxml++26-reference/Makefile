# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/textproc/libxml++26-reference/Makefile,v 1.1 2010/04/03 16:21:50 avl Exp $

PORTREVISION=	0

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/libxml++-2.6.pc:${PORTSDIR}/textproc/libxml++26 \
		glibmm-reference>=0:${PORTSDIR}/devel/glibmm-reference

USES=		gmake pkgconfig
GNU_CONFIGURE=	yes

DOCSDIR=	${PREFIX}/share/doc/libxml++-2.6

NO_STAGE=	yes
do-install:
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC} && ${GMAKE} install-data-local install-dist_referenceDATA
.endif

.include "${.CURDIR}/../../devel/glib20-reference/bsd.gnome-reference.mk"
