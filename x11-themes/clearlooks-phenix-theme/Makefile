# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	clearlooks-phenix
PORTVERSION=	6.0.3
CATEGORIES=	x11-themes xfce
PKGNAMESUFFIX=	-theme

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Gtk3 port of Clearlooks theme for the Xfce Desktop

LICENSE=	GPLv3

RUN_DEPENDS=	gtk-engines2>=2.20.2:x11-themes/gtk-engines2

USE_GITHUB=	yes
NO_BUILD=	yes

GH_ACCOUNT=	jpfleury

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/themes/Clearlooks-Phenix
.for dir in gtk-2.0 gtk-3.0 xfwm4
	@cd ${WRKSRC} && \
		${COPYTREE_SHARE} ${dir} \
		${STAGEDIR}${PREFIX}/share/themes/Clearlooks-Phenix
.endfor

.include <bsd.port.mk>
