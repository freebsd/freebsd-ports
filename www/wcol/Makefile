# New ports collection makefile for:	wcolEpre
# Version required:	980713_100245
# Date created:		17 July 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@kuis.kyoto-u.ac.jp>
#
# $FreeBSD$
#

DISTNAME=	wcolEpre.980713_100245
PKGNAME=	wcolEpre-1998.07.13
CATEGORIES=	www
MASTER_SITES=	http://shika.aist-nara.ac.jp/products/DEST/Wcol/

MAINTAINER=	shige@FreeBSD.ORG

WRKSRC=		${WRKDIR}/${DISTNAME}/src

GNU_CONFIGURE=	yes

STARTUP_SCRIPT=${PREFIX}/etc/rc.d/wcol.sh.sample

# wcol pooldir
DEFAULT_POOLDIR?=/var/spool/wcol
MAKE_ENV+=DEFAULT_POOLDIR=${DEFAULT_POOLDIR}

pre-patch:
	@${RM} -f ${WRKSRC}/../admin/killwcol.in
	@${MV} -f ${WRKSRC}/../admin/killwcol ${WRKSRC}/../admin/killwcol.in

post-install:
	@if [ ! -d ${DEFAULT_POOLDIR} ]; then \
	  ${ECHO} "Making wcol pool directory." ; \
	  ${MKDIR} ${DEFAULT_POOLDIR} ; \
	fi
	${TOUCH} /var/log/wcol.log

	@${ECHO} "Installing sample configuration file."
	@${INSTALL_DATA} ${WRKSRC}/wcol.conf-dist ${PREFIX}/etc/wcol.conf.sample

	@if [ ! -f ${STARTUP_SCRIPT} ]; then \
	  ${ECHO} "Installing ${STARTUP_SCRIPT} startup file." ; \
	  ${INSTALL_SCRIPT} ${FILESDIR}/wcol.sh.sample ${STARTUP_SCRIPT} ; \
	fi

.include <bsd.port.mk>
