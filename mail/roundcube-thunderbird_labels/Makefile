# Created by: Alexander Moisseev <moiseev@mezonplus.ru>
# $FreeBSD$

PORTNAME=	thunderbird_labels
PORTVERSION=	1.0.0
CATEGORIES=	mail
MASTER_SITES=	https://googledrive.com/host/
PKGNAMEPREFIX=	roundcube-
DISTNAME=	0B7cAkeuoAZKaMGVieHl4LTdEbWM
EXTRACT_SUFX=

MAINTAINER=	moiseev@mezonplus.ru
COMMENT=	Thunderbird Labels plugin for RoundCube webmail

LICENSE=	GPLv2

RUN_DEPENDS=	roundcube>=0.5:${PORTSDIR}/mail/roundcube

USES=		tar:bzip2
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
PLUGINDIR=	${WWWDIR:S,/${PORTNAME}$$,,}/roundcube/plugins/${PORTNAME}
PLUGINDIR_REL=	${WWWDIR_REL:S,/${PORTNAME}$$,,}/roundcube/plugins/${PORTNAME}
PLIST_SUB=	PLUGINDIR_REL="${PLUGINDIR_REL}"

# This target is only meant to be used by the port maintainer.
x-generate-plist: build
	make makeplist | \
	${SED} \
	    -e "s,^\(%%PLUGINDIR_REL%%/config\.inc\.php\.sample$$\),@sample \1," \
	    -e "/^%%PLUGINDIR_REL%%\/config\.inc\.php$$/d" \
	    -e "s,^\(@dirrm\)try\( %%PLUGINDIR_REL%%/\),\1\2," \
	    >${.CURDIR}/pkg-plist.tmp

do-install:
	${MKDIR} ${STAGEDIR}${PLUGINDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${PLUGINDIR}
	cd ${STAGEDIR}${PLUGINDIR} && \
		${CP} config.inc.php config.inc.php.sample

.include <bsd.port.mk>
