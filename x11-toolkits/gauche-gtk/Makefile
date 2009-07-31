# New ports collection makefile for:	Gauche-gtk
# Date created:			3 November 2002
# Whom:				Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	gauche
PORTVERSION=	0.4.1
PORTREVISION=	9
CATEGORIES=	x11-toolkits scheme
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gauche
PKGNAMESUFFIX=	-gtk
DISTNAME=	Gauche${PKGNAMESUFFIX}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	erik@smluc.org
COMMENT=	GTK2 binding for Gauche

BUILD_DEPENDS=	gosh:${PORTSDIR}/lang/gauche
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GNOME=	gtk20 # this alters CONFIGURE_TARGET!
GNU_CONFIGURE=	yes
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}/gtk
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}/gtk
PLIST_SUB=	VERSION="`gauche-config -V`" \
		TARGET="${MACHINE_ARCH}-portbld-freebsd${OSREL}"
CFLAGS+=	-fPIC

.if defined(WITH_GTKGLEXT)
LIB_DEPENDS+=	gtkglext-x11-1.0.0:${PORTSDIR}/x11-toolkits/gtkglext
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
