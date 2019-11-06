# Created by: Kevin Golding <kevin@caomhin.demon.co.uk>
# $FreeBSD$

PORTNAME=	webstats
PORTVERSION=	0.3
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://www.patsplanet.com/software/webstats/files/ \
		http://www.caomhin.org/geek/ports/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	kevin@caomhin.demon.co.uk
COMMENT=	Automated log file processing

BROKEN=		unfetchable

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/GPL

RUN_DEPENDS=	analog:www/analog \
		${LOCALBASE}/reportmagic/rmagic.pl:www/reportmagic

NO_BUILD=	yes
NO_ARCH=	yes
USES=		perl5 shebangfix
SHEBANG_FILES=	scripts/perl/webstats

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|%%PREFIX%%|${PREFIX}|' \
	   ${WRKSRC}/configfiles/serverwide/webstats.ini \
	   ${WRKSRC}/configfiles/vhosts/analog.cfg \
	   ${WRKSRC}/configfiles/vhosts/rmagic.ini \
	   ${WRKSRC}/scripts/perl/webstats \
	   ${WRKSRC}/scripts/php/webstats.php

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/webstats
	@${MKDIR} ${STAGEDIR}${PREFIX}/webstats/stuff
	@${MKDIR} ${STAGEDIR}${PREFIX}/webstats/web
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/webstats
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/webstats/vhosts
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/perl/webstats \
	   ${STAGEDIR}${PREFIX}/webstats/webstats
	${INSTALL_DATA} ${WRKSRC}/configfiles/serverwide/webstats.ini \
	   ${STAGEDIR}${PREFIX}/etc/webstats/webstats.ini-dist
	${INSTALL_DATA} ${WRKSRC}/configfiles/serverwide/default.cfg \
	   ${STAGEDIR}${PREFIX}/etc/webstats/default.cfg-dist
	${INSTALL_DATA} ${WRKSRC}/configfiles/serverwide/default.ini \
	   ${STAGEDIR}${PREFIX}/etc/webstats/default.ini-dist
	${INSTALL_DATA} ${WRKSRC}/configfiles/vhosts/analog.cfg \
	   ${STAGEDIR}${PREFIX}/etc/webstats/vhosts/analog.cfg-dist
	${INSTALL_DATA} ${WRKSRC}/configfiles/vhosts/rmagic.ini \
	   ${STAGEDIR}${PREFIX}/etc/webstats/vhosts/rmagic.ini-dist
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${PREFIX}/webstats/README
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${STAGEDIR}${PREFIX}/webstats/INSTALL
	${INSTALL_DATA} ${WRKSRC}/VERSION ${STAGEDIR}${PREFIX}/webstats/VERSION
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${STAGEDIR}${PREFIX}/webstats/CHANGES
	${INSTALL_DATA} ${WRKSRC}/docs/index.html \
	   ${STAGEDIR}${PREFIX}/share/doc/webstats.html
	${INSTALL_DATA} ${WRKSRC}/scripts/php/bullet.gif \
	   ${STAGEDIR}${PREFIX}/webstats/web/bullet.gif
	${INSTALL_DATA} ${WRKSRC}/scripts/php/class.inifile.php \
	   ${STAGEDIR}${PREFIX}/webstats/web/class.inifile.php
	${INSTALL_DATA} ${WRKSRC}/scripts/php/menu.css \
	   ${STAGEDIR}${PREFIX}/webstats/web/menu.css
	${INSTALL_DATA} ${WRKSRC}/scripts/php/webstats.php \
	   ${STAGEDIR}${PREFIX}/webstats/web/webstats.php
	${INSTALL_DATA} ${WRKSRC}/stuff/README \
	   ${STAGEDIR}${PREFIX}/webstats/stuff/README
	${INSTALL_DATA} ${WRKSRC}/stuff/advxsplitlogfile \
	   ${STAGEDIR}${PREFIX}/webstats/stuff/advxsplitlogfile
	${INSTALL_DATA} ${WRKSRC}/stuff/DynamicVhosts.conf \
	   ${STAGEDIR}${PREFIX}/webstats/stuff/DynamicVhosts.conf

.include <bsd.port.mk>
