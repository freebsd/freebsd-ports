# New ports collection makefile for:	junkbuster
# Version required:	2.0
# Date created:		2 May 1998
# Whom:			Ian Struble <ian@broken.net>
#
# $Id: Makefile,v 1.1.1.1 1998/05/03 20:51:37 mph Exp $

DISTNAME=	ijb20
PKGNAME=	ijb-2.0.2
CATEGORIES=	www
MASTER_SITES=	http://www.junkbusters.com/ht/en/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ian@broken.net

FETCH_BEFORE_ARGS=	-b

MAN1=		junkbuster.1

# We have to do the install ourselves...
do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/$(DISTNAME)/junkbuster ${PREFIX}/bin/junkbuster
	${MKDIR} -m 755 ${PREFIX}/etc/junkbuster
	${INSTALL_DATA} ${WRKDIR}/$(DISTNAME)/junkbstr.ini ${PREFIX}/etc/junkbuster/configfile.sample
	${INSTALL_DATA} ${WRKDIR}/$(DISTNAME)/sblock.ini ${PREFIX}/etc/junkbuster/blockfile.sample
	${INSTALL_DATA} ${WRKDIR}/$(DISTNAME)/saclfile.ini ${PREFIX}/etc/junkbuster/aclfile.sample
	${INSTALL_DATA} ${WRKDIR}/$(DISTNAME)/scookie.ini ${PREFIX}/etc/junkbuster/cookiefile.sample
	${INSTALL_DATA} ${WRKDIR}/$(DISTNAME)/sforward.ini ${PREFIX}/etc/junkbuster/forwardfile.sample
	${INSTALL_DATA} ${WRKDIR}/$(DISTNAME)/strust.ini ${PREFIX}/etc/junkbuster/trustfile.sample
	$(INSTALL_MAN) $(WRKDIR)/$(DISTNAME)/junkbuster.1 $(PREFIX)/man/man1/

.include <bsd.port.mk>
