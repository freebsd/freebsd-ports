# New ports collection makefile for:	wcolEpre
# Date created:		17 July 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wcolEpre
PORTVERSION=	1999.01.10
CATEGORIES=	www
MASTER_SITES=	http://shika.aist-nara.ac.jp/products/DEST/Wcol/
DISTNAME=	wcolEpre.990110_150126

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A prefetching proxy server for WWW

WRKSRC=		${WRKDIR}/${DISTNAME}/src

GNU_CONFIGURE=	yes

# startup script
WCOL_STARTUP=	wcol.sh.sample
STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/wcol.sh

# wcol pooldir
DEFAULT_POOLDIR?=	/var/spool/wcol
MAKE_ENV+=		DEFAULT_POOLDIR=${DEFAULT_POOLDIR}

# wcol sample configuration file
WCOL_CONF_DIST=		${WRKSRC}/wcol.conf-dist-FreeBSD
WCOL_CONF=		${PREFIX}/etc/wcol.conf.sample

pre-patch:
	@${RM} -f ${WRKSRC}/../admin/killwcol.in
	@${MV} -f ${WRKSRC}/../admin/killwcol ${WRKSRC}/../admin/killwcol.in

pre-configure:
	@(cd ${WRKSRC} ; \
	  ${RM} -f ${WCOL_CONF_DIST} ; \
	  ${CAT} wcol.conf-dist | \
	  ${SED} -e "s;@@DEFAULT_POOLDIR@@;${DEFAULT_POOLDIR};g" \
		> ${WCOL_CONF_DIST} ; \
	  ${RM} -f ${WCOL_STARTUP} ; \
	  ${CAT} ${FILESDIR}/${WCOL_STARTUP} | \
	  ${SED} -e "s;@@DEFAULT_POOLDIR@@;${DEFAULT_POOLDIR};g" \
	         -e "s;@@PREFIX@@;${PREFIX};g" \
		> ${WRKSRC}/${WCOL_STARTUP} ; \
	)
	

post-install:
	@if [ ! -d ${DEFAULT_POOLDIR} ]; then \
	  ${ECHO} "Making wcol pool directory." ; \
	  ${MKDIR} ${DEFAULT_POOLDIR} ; \
	fi
	@${ECHO} "Installing sample configuration file."
	@${INSTALL_DATA} ${WCOL_CONF_DIST} ${WCOL_CONF}
	@${ECHO} "Installing ${STARTUP_SCRIPT} startup file."
	@${INSTALL_SCRIPT} ${WRKSRC}/wcol.sh.sample ${STARTUP_SCRIPT}

.include <bsd.port.mk>
