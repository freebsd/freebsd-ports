# New ports collection makefile for:	xlogmaster
# Version required:	1.4.3
# Date created:		1 August 1998
# Whom:			Adrian Wontroba <aw1@stade.co.uk>
#
# $Id$
#

DISTNAME=	xlogmaster-1.4.3
CATEGORIES=	sysutils
MASTER_SITES=	ftp://sunsite.doc.ic.ac.uk/packages/gnu/\
		${MASTER_SITE_GNU}\
		http://www.fusebox.hanse.de/xlogmaster/development/\
		http://porter.desy.de/~greve/xlogmaster/development/

MAINTAINER=	aw1@stade.co.uk

LIB_DEPENDS=	gtk\\.1\\.5:${PORTSDIR}/x11-toolkits/gtk

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CXXFLAGS="${CFLAGS}"
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
