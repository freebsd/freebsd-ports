PORTNAME=	claws-mail-themes
PORTVERSION=	20140629
CATEGORIES=	x11-themes mail
MASTER_SITES=	http://www.claws-mail.org/themes/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Claws Mail icon themes

LICENSE=	UNKNOWN
LICENSE_NAME=	@${LICENSE_TEXT}
LICENSE_TEXT=	Licenses for the themes in this port range from GPLv2 \
		to Public Domain. In all cases, these themes are free to use. \
		Please read the licenses, if any, located in the root of each theme \
		for other possible rescrictions.
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

NO_ARCH=	yes
NO_BUILD=	yes

THEMESDIR?=	${PREFIX}/share/claws-mail/themes

do-install:
	@${MKDIR} ${STAGEDIR}${THEMESDIR}
	    cd ${WRKSRC}/ && ${FIND} . -mindepth 2 -print | \
		${GREP} -vE '(Makefile.*|INSTALL)' | \
		${CPIO} -pdu -R ${BINOWN}:${BINGRP} --quiet ${STAGEDIR}${THEMESDIR}
	@${CHMOD} -R a+r ${STAGEDIR}${THEMESDIR}
	@${FIND} ${STAGEDIR}${THEMESDIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@${FIND} ${STAGEDIR}${THEMESDIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 644

.include <bsd.port.mk>
