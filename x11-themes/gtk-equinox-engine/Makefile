# New ports collection makefile for:	gtk-equinox-engine
# Date created:		2010-10-23
# Whom:			Deni Shaposhnikov <dsh@bamus.cz>
#
# $FreeBSD$
#

PORTNAME=	equinox
PORTVERSION=	1.30.2
CATEGORIES=	x11-themes
MASTER_SITES=	http://gnome-look.org/CONTENT/content-files/
PKGNAMEPREFIX=	gtk-
PKGNAMESUFFIX=	-engine
DISTNAME=	121881-equinox-1.30

MAINTAINER=	dsh@bamus.cz
COMMENT=	Equinox GTK+ 2.x engine and themes

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gtk-engines-2.pc:${PORTSDIR}/x11-themes/gtk-engines2
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gtk-engines-2.pc:${PORTSDIR}/x11-themes/gtk-engines2

USE_BZIP2=	yes
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/equinox-1.30

DATADIR=	${PREFIX}/share/themes

SUBDIRS=	Equinox "Equinox Classic" "Equinox Classic Glass" \
		"Equinox Evolution" "Equinox Evolution Light" \
		"Equinox Evolution Rounded" "Equinox Evolution Squared" \
		"Equinox Glass" "Equinox Light" "Equinox Light Glass" \
		"Equinox Wide"

OPTIONS=	ANIMATION "Enable animation support" on

.include <bsd.port.pre.mk>

.if defined(WITH_ANIMATION)
CONFIGURE_ARGS+=	--enable-animation
.endif

post-extract:
	@cd ${WRKDIR} && ${TAR} zxf equinox-gtk-engine.tar.gz
	@cd ${WRKDIR} && ${TAR} zxf equinox-themes.tar.gz

post-patch:
	@${FIND} ${WRKDIR} -name 'gtkrc' -exec \
	    ${REINPLACE_CMD} -e 's!^include "apps/nautilus\.rc"!#&!' {} +
	@${FIND} ${WRKDIR} -type f -name 'gtkrc.bak' -exec ${RM} -f {} +

post-install:
	@${MKDIR} ${DATADIR}
.for i in ${SUBDIRS}
	${CP} -R ${WRKDIR}/${i} ${DATADIR}
	${FIND} ${DATADIR}/${i} -type d -exec ${CHMOD} 755 {} +
	${FIND} ${DATADIR}/${i} -type f -exec ${CHMOD} ${SHAREMODE} {} +
.endfor
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
.for i in "Equinox Evolution.crx" userChrome.css
	${INSTALL_DATA} ${WRKDIR}/$i ${EXAMPLESDIR}
.endfor
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
