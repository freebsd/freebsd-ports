# New ports collection makefile for:	dnews
# Version required:     42j
# Date created:		Thu May 29 17:16:36 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.7 1998/01/31 15:52:32 andreas Exp $
#

DISTNAME=	dnews
PKGNAME=	dnews-4.6n
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.netwinsite.com/pub/netwinsite/dnews/
DISTFILES=	dnews46n_freebsd.tar.Z

MAINTAINER=	andreas@FreeBSD.ORG

NO_CDROM=	"no answer yet, if we are allowed to put it onto CDROM"
RESTRICTED=	"only free for non-profit organisations"
NO_PACKAGE=	"${RESTRICTED}"

# nothing to make, binary only
NO_BUILD=		yes

# new: the dnews_setup script is the standard install program
# it asks you questions and makes life easier for you and me

do-install:
	@( cd ${WRKSRC}; ./dnews_setup )
	@${ECHO_MSG} "*** DNEWS is NOT free, please read the LICENSE file !!!"
	@${ECHO_MSG} "*** ${PREFIX}/share/doc/dnews/license.txt"
	@${ECHO_MSG} "*** The main configuration file is:"
	@${ECHO_MSG} "***	/etc/dnews.conf"

.include <bsd.port.mk>
