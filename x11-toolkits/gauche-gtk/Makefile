# New ports collection makefile for:	Gauche-gtk
# Date created:			3 November 2002
# Whom:				Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	gtk
PORTVERSION=	0.3
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gauche
PKGNAMEPREFIX=	gauche-
DISTNAME=	Gauche-${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	fuyuki@hadaly.org

LIB_DEPENDS=	gtk-x11-2.0.200:${PORTSDIR}/x11-toolkits/gtk20
BUILD_DEPENDS=	gosh:${PORTSDIR}/lang/gauche
RUN_DEPENDS=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
EXAMPLESDIR=	${PREFIX}/share/examples/gauche/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/gauche/${PORTNAME}
PLIST_SUB=	VERSION="`gauche-config -V`" \
		TARGET="${CONFIGURE_TARGET}"

.if defined(WITH_GTKGLEXT)
LIB_DEPENDS+=	gtkglext-x11-1.0:${PORTSDIR}/x11-toolkits/gtkglext
CONFIGURE_ARGS=	--enable-gtkgl
PLIST_SUB+=	GTKGLEXT=""
.else
PLIST_SUB+=	GTKGLEXT="@comment "
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.scm ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/gtk-tutorial ${EXAMPLESDIR}
.if defined(WITH_GTKGLEXT)
	${CP} -R ${WRKSRC}/examples/gtkglext ${EXAMPLESDIR}
.endif
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
