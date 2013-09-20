# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	clearlooks-phenix
PORTVERSION=	3.0.15
CATEGORIES=	x11-themes xfce
MASTER_SITES=	GOOGLE_CODE
PKGNAMESUFFIX=	-theme

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Gtk3 port of Clearlooks theme for the Xfce Desktop

RUN_DEPENDS=	gtk3-unico-engine>=1.0.1:${PORTSDIR}/x11-themes/gtk3-unico-engine

PROJECTHOST=	olivier-freebsd-ports

USE_XZ=	yes
NO_BUILD=	yes

NO_STAGE=	yes
do-install:
	@${MKDIR} ${PREFIX}/share/themes/Clearlooks-Phenix
.for dir in gtk-2.0 gtk-3.0 xfwm4
	@cd ${WRKSRC} && \
		${COPYTREE_SHARE} ${dir} ${PREFIX}/share/themes/Clearlooks-Phenix
.endfor

.include <bsd.port.mk>
