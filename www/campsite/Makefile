# New ports collection makefile for:	campsite
# Date created:				5 August 2005
# Whom:					Ondra Koutek <koutek@o-k.cz>
#
# $FreeBSD$
#

PORTNAME=	campsite
PORTVERSION=	2.6.7
PORTREVISION=	5
CATEGORIES=	www
MASTER_SITES=	SF

MAINTAINER=	koutek@o-k.cz
COMMENT=	The free and open multilingual web publishing tool for news sites

LIB_DEPENDS=	idn.16:${PORTSDIR}/dns/libidn \
		GraphicsMagick.1:${PORTSDIR}/graphics/GraphicsMagick
BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		gm4:${PORTSDIR}/devel/m4 \
		pear:${PORTSDIR}/devel/pear
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		${LOCALBASE}/share/pear/HTTP/Client.php:${PORTSDIR}/www/pear-HTTP_Client \
		${LOCALBASE}/share/pear/File.php:${PORTSDIR}/sysutils/pear-File \
		${LOCALBASE}/share/pear/File/Find.php:${PORTSDIR}/sysutils/pear-File_Find \
		${LOCALBASE}/share/pear/XML/Util.php:${PORTSDIR}/devel/pear-XML_Util \
		${LOCALBASE}/share/pear/XML/Parser.php:${PORTSDIR}/devel/pear-XML_Parser

MAKE_JOBS_UNSAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_APACHE=	13

USE_PHP=	mysql curl pcre xml xmlrpc gd session
WANT_PHP_CLI=	YES
USE_PHP_BUILD=	YES

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--apache_user ${WWWOWN} --apache_group ${WWWGRP} --prefix ${PREFIX}

USE_GMAKE=	yes

SUB_FILES+=	pkg-message pkg-install pkg-deinstall crontab.in

post-patch:
	@${FIND} ${WRKSRC} -type f -perm 755 \
			    -or -name campsite_create_instance \
			    -or -name global_functions \
			    -or -name check4_functions \
			    -or -name conf_functions | ${XARGS} \
			${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|'
	@${FIND} ${WRKSRC} -type f -name autopublish | ${XARGS} \
			${REINPLACE_CMD} -e 's|php |${LOCALBASE}/bin/php |'
	@${FIND} ${WRKSRC} -type f -name "*.php" | ${XARGS} \
			${REINPLACE_CMD} -e 's|$cmd = "pushd |$cmd = "${LOCALBASE}/bin/bash -c \\\"pushd |'
	@${FIND} ${WRKSRC} -type f -name "*.php" | ${XARGS} \
			${REINPLACE_CMD} -e 's|popd > /dev/null";|popd > /dev/null\\\"";|'
	@${FIND} ${WRKSRC} -name "*.bak" -delete

post-install:
	@${INSTALL_DATA} ${WRKDIR}/crontab.in ${PREFIX}/campsite/etc
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
