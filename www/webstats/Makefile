# New ports collection makefile for:   webstats
# Date created:        12 February 2003
# Whom:                Kevin Golding <kevin@caomhin.demon.co.uk>
#
# $FreeBSD$
#

PORTNAME=	webstats
PORTVERSION=	0.3
CATEGORIES=	www
MASTER_SITES=	http://www.patsplanet.com/software/webstats/files/ \
		http://www.caomhin.org/geek/ports/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	kevin@caomhin.demon.co.uk
COMMENT=	Automated log file processing

RUN_DEPENDS=	analog:${PORTSDIR}/www/analog \
		${LOCALBASE}/reportmagic/rmagic.pl:${PORTSDIR}/www/reportmagic

NO_BUILD=	yes
USE_PERL5=	yes

post-patch:
	@${PERL} -pi -e 's|%%PREFIX%%|${PREFIX}|g' \
	   ${WRKSRC}/configfiles/serverwide/webstats.ini
	@${PERL} -pi -e 's|%%PREFIX%%|${PREFIX}|g' \
	   ${WRKSRC}/configfiles/vhosts/analog.cfg
	@${PERL} -pi -e 's|%%PREFIX%%|${PREFIX}|g' \
	   ${WRKSRC}/configfiles/vhosts/rmagic.ini
	@${PERL} -pi -e 's|%%PREFIX%%|${PREFIX}|g' \
	   ${WRKSRC}/scripts/perl/webstats
	@${PERL} -pi -e 's|%%PREFIX%%|${PREFIX}|g' \
	   ${WRKSRC}/scripts/php/webstats.php

do-install:
	@${MKDIR} ${PREFIX}/webstats
	@${MKDIR} ${PREFIX}/webstats/stuff
	@${MKDIR} ${PREFIX}/webstats/web
	@${MKDIR} ${PREFIX}/etc/webstats
	@${MKDIR} ${PREFIX}/etc/webstats/vhosts
	@${INSTALL_SCRIPT} ${WRKSRC}/scripts/perl/webstats \
	   ${PREFIX}/webstats/webstats
	@${INSTALL_DATA} ${WRKSRC}/configfiles/serverwide/webstats.ini \
	   ${PREFIX}/etc/webstats/webstats.ini-dist
	@${INSTALL_DATA} ${WRKSRC}/configfiles/serverwide/default.cfg \
	   ${PREFIX}/etc/webstats/default.cfg-dist
	@${INSTALL_DATA} ${WRKSRC}/configfiles/serverwide/default.ini \
	   ${PREFIX}/etc/webstats/default.ini-dist
	@${INSTALL_DATA} ${WRKSRC}/configfiles/vhosts/analog.cfg \
	   ${PREFIX}/etc/webstats/vhosts/analog.cfg-dist
	@${INSTALL_DATA} ${WRKSRC}/configfiles/vhosts/rmagic.ini \
	   ${PREFIX}/etc/webstats/vhosts/rmagic.ini-dist
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/webstats/README
	@${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/webstats/INSTALL
	@${INSTALL_DATA} ${WRKSRC}/VERSION ${PREFIX}/webstats/VERSION
	@${INSTALL_DATA} ${WRKSRC}/CHANGES ${PREFIX}/webstats/CHANGES
	@${INSTALL_DATA} ${WRKSRC}/docs/index.html \
	   ${PREFIX}/share/doc/webstats.html
	@${INSTALL_DATA} ${WRKSRC}/scripts/php/bullet.gif \
	   ${PREFIX}/webstats/web/bullet.gif
	@${INSTALL_DATA} ${WRKSRC}/scripts/php/class.inifile.php \
	   ${PREFIX}/webstats/web/class.inifile.php
	@${INSTALL_DATA} ${WRKSRC}/scripts/php/menu.css \
	   ${PREFIX}/webstats/web/menu.css
	@${INSTALL_DATA} ${WRKSRC}/scripts/php/webstats.php \
	   ${PREFIX}/webstats/web/webstats.php
	@${INSTALL_DATA} ${WRKSRC}/stuff/README \
	   ${PREFIX}/webstats/stuff/README
	@${INSTALL_DATA} ${WRKSRC}/stuff/advxsplitlogfile \
	   ${PREFIX}/webstats/stuff/advxsplitlogfile
	@${INSTALL_DATA} ${WRKSRC}/stuff/DynamicVhosts.conf \
	   ${PREFIX}/webstats/stuff/DynamicVhosts.conf

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
