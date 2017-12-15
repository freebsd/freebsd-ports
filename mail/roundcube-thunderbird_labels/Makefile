# Created by: Alexander Moisseev <moiseev@mezonplus.ru>
# $FreeBSD$

PORTNAME=	thunderbird_labels
PORTVERSION=	1.1.4
DISTVERSIONPREFIX=	v
CATEGORIES=	mail
PKGNAMEPREFIX=	roundcube-

MAINTAINER=	moiseev@mezonplus.ru
COMMENT=	Thunderbird Labels plugin for RoundCube webmail

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	roundcube>=0.5:mail/roundcube

NO_BUILD=	yes
NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	mike-kfed
GH_PROJECT=	rcmail-thunderbird-labels

PLUGINDIR=	${WWWDIR:S,/${PORTNAME}$$,,}/roundcube/plugins/${PORTNAME}
PLUGINDIR_REL=	${WWWDIR_REL:S,/${PORTNAME}$$,,}/roundcube/plugins/${PORTNAME}
PLIST_SUB=	PLUGINDIR_REL="${PLUGINDIR_REL}"

OPTIONS_DEFINE=	DOCS

# This target is only meant to be used by the port maintainer.
x-generate-plist: build
	make makeplist | \
	${SED} \
	    -e "s,^\(%%PLUGINDIR_REL%%/config\.inc\.php\.sample$$\),@sample \1," \
	    -e "s,^\(%%PLUGINDIR_REL%%/docs/\),%%PORTDOCS%%\1," \
	    >${.CURDIR}/pkg-plist.tmp

do-install:
	@${MKDIR} ${STAGEDIR}${PLUGINDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PLUGINDIR}
	cd ${STAGEDIR}${PLUGINDIR} && \
		${MV} config.inc.php config.inc.php.sample

.include <bsd.port.mk>
