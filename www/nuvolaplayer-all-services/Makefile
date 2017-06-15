# $FreeBSD$

PORTNAME=	nuvolaplayer
PORTVERSION?=	1.0
# Do not set PORTREVISION here.
CATEGORIES?=	www audio

MAINTAINER?=	avilla@FreeBSD.org

.include "Makefile.services"

_DATADIR=	${PREFIX}/share/${PORTNAME}3

.ifndef(MASTERDIR)
PORTREVISION=	0
PKGNAMESUFFIX=	-all-services

COMMENT=	Web app integrations for Nuvola Player

USES=		metaport

OPTIONS_DEFINE=	${NV_SERVICES}
OPTIONS_DEFAULT=${OPTIONS_DEFINE}

. for o in ${OPTIONS_DEFINE}
${o}_DESC=	${NV_${o}_DESC} support
${o}_RUN_DEPENDS=${_DATADIR:S,^${PREFIX}/,${LOCALBASE}/,}/web_apps/${NV_${o}_NAME:S/-/_/g}/metadata.json:www/${PORTNAME}-${NV_${o}_NAME}
. endfor
.else
NV_ID=		${${.CURDIR:T:S/${PORTNAME}-//}_ID}

PORTVERSION=	${NV_${NV_ID}_VERSION}
PORTREVISION?=	${NV_${NV_ID}_REVISION}
PKGNAMESUFFIX?=	-${NV_${NV_ID}_NAME}

COMMENT?=	${NV_${NV_ID}_DESC} integration for Nuvola Player

LICENSE?=	BSD2CLAUSE

.ifdef(NV_${NV_ID}_LICENSE)
LICENSE=	${NV_${NV_ID}_LICENSE}
.endif

.ifdef(NV_${NV_ID}_LICENSE_COMB)
LICENSE_COMB=	${NV_${NV_ID}_LICENSE_COMB}
.endif

BUILD_DEPENDS+=	lasem-render:textproc/lasem \
		scour:textproc/py-scour

USE_GITHUB=	yes
GH_ACCOUNT?=	tiliado
GH_PROJECT?=	nuvola-app${PKGNAMESUFFIX}

USES+=		gmake
NO_ARCH=	yes
ALL_TARGET?=	build
MAKE_ARGS+=	DEST=${STAGEDIR}${_DATADIR}/web_apps
INSTALLS_ICONS=	yes

DISTINFO_FILE?=	${.CURDIR}/distinfo
PLIST?=		${PKGDIR}/pkg-plist.service

PLIST_FILES?=	${NV_${NV_ID}_PLIST_FILES}
PLIST_SUB+=	SERVICE="${NV_${NV_ID}_NAME:S/-/_/g}"

DATADIR=	${_DATADIR}/web_apps/${NV_${NV_ID}_NAME:S/-/_/g}

pre-build:
# Do not install license files, the Ports framework takes care of it.
	@${REINPLACE_CMD} -E -e 's,icons/icon,src/icon,' \
		-e '/install/ s,-t ([^ ]+)(.+),\2 \1,' \
		-e '/ln/ s,-T,,' \
		-e 's,\$$\(LICENSES),,' \
		${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>
