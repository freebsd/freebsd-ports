# New ports collection makefile for:	libgnomeprint
# Date created:				15 Jan 1999
# Whom:					Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgnomeprint
PORTVERSION=	2.4.1
PORTREVISION=	2
CATEGORIES=	print gnome
MASTER_SITES=	${MASTER_SITE_GNOME} \
		${MASTER_SITE_LOCAL:S/$/:local/} \
		http://people.FreeBSD.org/~marcus/:local
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.4 \
			marcus/:local
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		gpa-xml-${PORTVERSION}${EXTRACT_SUFX}:local
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome print support library

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomehier libbonobo libartlgpl2 gtk20
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_SUB=	VERSION=${PORTVERSION}

GPA_XML=	globals.xml
GPA_PRINTERS=	GENERIC.xml META.xml PDF-WRITER.xml
GPA_MODELS=	GNOME-GENERIC-PS.xml GNOME-META.xml GNOME-PDF-WRITER.xml

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libcups.so)
WITH_CUPS=	yes
.endif

.if defined(WITH_CUPS) && !defined(WITHOUT_CUPS)
CONFIGURE_ARGS+=	--with-cups
LIB_DEPENDS+=		cups.2:${PORTSDIR}/print/cups-base
PLIST_SUB+=		CUPS:=""
.else
CONFIGURE_ARGS+=	--without-cups
PLIST_SUB+=		CUPS:="@comment "
.endif

post-patch:
	@${FIND} ${WRKSRC} -name '*.[ch]' | ${XARGS} ${REINPLACE_CMD} -e \
		's|<malloc[.]h>|<stdlib.h>|'
	@${REINPLACE_CMD} -e "/^SUBDIRS =/s|tests||" ${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${PREFIX}/etc/gnome/libgnomeprint-2.0/fonts
	@${TOUCH} ${PREFIX}/etc/gnome/libgnomeprint-2.0/fonts/gnome-print.fontmap
.for xml in ${GPA_XML}
	${INSTALL_DATA} ${WRKDIR}/gpa-xml-${PORTVERSION}/${xml} \
		${PREFIX}/share/gnome/${PORTNAME}/${PORTVERSION}
.endfor
.for printer in ${GPA_PRINTERS}
	${INSTALL_DATA} ${WRKDIR}/gpa-xml-${PORTVERSION}/${printer} \
		${PREFIX}/share/gnome/${PORTNAME}/${PORTVERSION}/printers
.endfor
.for model in ${GPA_MODELS}
	${INSTALL_DATA} ${WRKDIR}/gpa-xml-${PORTVERSION}/${model} \
		${PREFIX}/share/gnome/${PORTNAME}/${PORTVERSION}/models
.endfor

.include <bsd.port.post.mk>
