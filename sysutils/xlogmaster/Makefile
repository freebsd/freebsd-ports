# New ports collection makefile for:	xlogmaster
# Version required:	1.4.4
# Date created:		1 August 1998
# Whom:			Adrian Wontroba <aw1@stade.co.uk>
#
# $Id: Makefile,v 1.8 1998/09/22 22:55:55 asami Exp $
#

DISTNAME=	xlogmaster-1.4.4
CATEGORIES=	sysutils
MASTER_SITES=	ftp://sunsite.doc.ic.ac.uk/packages/gnu/\
		${MASTER_SITE_GNU}\
		http://www.fusebox.hanse.de/xlogmaster/development/\
		http://porter.desy.de/~greve/xlogmaster/development/
MASTER_SITE_SUBDIR=	xlogmaster

MAINTAINER=	aw1@stade.co.uk

LIB_DEPENDS=	gtk11.1:${PORTSDIR}/x11-toolkits/gtk11

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CXXFLAGS="${CFLAGS}" GTK_CONFIG="${PREFIX}/bin/gtk11-config"
USE_X_PREFIX=	yes
USE_GMAKE=	yes

MAN1=		xlogmaster.1

post-patch:
	cd ${WRKSRC}/doc && ln -s tutorial.texinfo xlogmaster.texinfo

post-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	 fi
	@install-info ${PREFIX}/info/xlogmaster.info ${PREFIX}/info/dir
	@install-info ${PREFIX}/info/xlogmaster_faq.info ${PREFIX}/info/dir

.include <bsd.port.mk>
