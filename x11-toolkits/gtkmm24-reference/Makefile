# New ports collection makefile for:	gtkmm24-reference
# Date created:				09 May 2006
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	7

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gtkmm-2.4.pc:${PORTSDIR}/x11-toolkits/gtkmm24 \
		${LOCALBASE}/share/glibmm-2.4/doctool/doc-install.pl:${PORTSDIR}/devel/glibmm-reference

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

DOCSDIR=	${PREFIX}/share/doc/gtkmm-2.4

do-install:
.if !defined(NOPORTDOCS)
.for d in docs
	@cd ${WRKSRC}/${d} && ${GMAKE} install
.endfor
.endif

.include "${.CURDIR}/../../devel/glib20-reference/bsd.gnome-reference.mk"
