# New ports collection makefile for:	V.E.R.A.
# Version required:	1.5
# Date created:		9 March 1999
# Whom:			Dima Sivachenko	<dima@chg.ru>
#
# $Id $
#

DISTNAME=	vera-1.5
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	vera

MAINTAINER=	dima@Chg.RU

do-build:
		@ cd ${WRKSRC} && makeinfo vera.texi

do-install:
		@ ${INSTALL_DATA} ${WRKSRC}/vera.info* ${PREFIX}/info

post-install:
	if [ ! -f ${PREFIX}/info/dir ]; then	\
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
	@ install-info ${PREFIX}/info/vera.info ${PREFIX}/info/dir

.include <bsd.port.mk>
