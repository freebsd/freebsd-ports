PORTNAME=	pocillo-gtk
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12.1
CATEGORIES=	x11-themes
MASTER_SITES=	https://github.com/UbuntuBudgie/${PORTNAME}-theme/releases/download/${DISTVERSIONFULL}/
PKGNAMESUFFIX=	-themes
DISTFILES=	pocillo-precompiled-qogir.tar.gz

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	Material design theme for the Budgie desktop
WWW=		https://github.com/UbuntuBudgie/pocillo-gtk-theme

LICENSE=	GPLv2+

RUN_DEPENDS=	roboto-fonts-ttf>0:x11-fonts/roboto-fonts-ttf \
		qogir-icon-themes>0:x11-themes/qogir-icon-themes

NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

THEMESDIR=	${STAGEDIR}${PREFIX}/share/themes
_CHILD_THEME=	dark \
		darkest \
		frappe \
		light

pre-install:
.for d in Pocillo Pocillo-slim
	@${MKDIR} ${THEMESDIR}/${d}
. for c in ${_CHILD_THEME}
	@${MKDIR} ${THEMESDIR}/${d}-${c}
. endfor
.endfor

do-install:
.for d in Pocillo Pocillo-slim
	cd ${WRKSRC}/${d} && ${COPYTREE_SHARE} . ${THEMESDIR}/${d}/ \
		"! -name *\.md"
. for c in ${_CHILD_THEME}
	cd ${WRKSRC}/${d}-${c} && ${COPYTREE_SHARE} . ${THEMESDIR}/${d}-${c}/ \
		"! -name *\.md"
. endfor
.endfor

.include <bsd.port.mk>
