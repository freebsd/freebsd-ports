# New ports collection makefile for:	gtar
# Version required:	1.12
# Date created:		Sa   6 Jun 1998 10:24:51 CEST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.3 1998/12/24 19:16:27 asami Exp $
#

DISTNAME=	tar-1.12
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	tar

MAINTAINER=	andreas@FreeBSD.ORG

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=--program-prefix=g

pre-install:
	if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi

.include <bsd.port.mk>
