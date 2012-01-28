# New ports collection makefile for:	gtk-equinox-engine
# Date created:		2010-10-23
# Whom:			Deni Shaposhnikov <dsh@bamus.cz>
#
# $FreeBSD$
#

PORTNAME=	equinox
PORTVERSION=	1.50
PORTREVISION=	1
CATEGORIES=	x11-themes
MASTER_SITES=	http://gnome-look.org/CONTENT/content-files/
PKGNAMEPREFIX=	gtk-
PKGNAMESUFFIX=	-engine
DISTFILES=	121881-${PORTNAME}-${PORTVERSION}.tar.gz \
		140449-${PORTNAME}-themes-${PORTVERSION}.tar.gz

MAINTAINER=	dsh@bamus.cz
COMMENT=	Equinox GTK+ 2.x engine and themes

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gtk-engines-2.pc:${PORTSDIR}/x11-themes/gtk-engines2
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gtk-engines-2.pc:${PORTSDIR}/x11-themes/gtk-engines2 \
		${LOCALBASE}/share/icons/Faenza/index.theme:${PORTSDIR}/x11-themes/gnome-icons-faenza

USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/equinox-${PORTVERSION}

DATADIR=	${PREFIX}/share/themes

SUBDIRS=	"Equinox Evolution" "Equinox Evolution Dawn" \
		"Equinox Evolution Dawn" "Equinox Evolution Dusk" \
		"Equinox Evolution Light" "Equinox Evolution Midnight" \
		"Equinox Evolution Rounded" "Equinox Evolution Squared"
EXAMPLES=	"Equinox Evolution.crx" "Equinox Evolution Dawn.crx" \
		"Equinox Evolution Dusk.crx" "Equinox Evolution Midnight.crx"

OPTIONS=	ANIMATION "Enable animation support" on

.include <bsd.port.options.mk>

.if defined(WITH_ANIMATION)
CONFIGURE_ARGS+=	--enable-animation
.endif

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
.for i in ${EXAMPLES}
	${INSTALL_DATA} ${WRKDIR}/$i ${EXAMPLESDIR}
.endfor
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
