# New ports collection makefile for:   gallery
# Date created:                09 Sep 2001
# Whom:                        Jamie Hermans <jamie@hermans.ca>
#
# $FreeBSD$
#

PORTNAME=	gallery
PORTVERSION=	1.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	jamie@hermans.ca

RUN_DEPENDS=	${LOCALBASE}/share/netpbm:${PORTSDIR}/graphics/netpbm

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

post-extract:
	cd ${WRKDIR}; \
		${FETCH_CMD} http://www.sentex.net/~mwandel/jhead/jhead

do-install:
	${MKDIR} -v ${PREFIX}/www/data
	cd ${WRKDIR}; \
		${INSTALL_PROGRAM} jhead ${PREFIX}/bin
	cd ${WRKDIR}; \
		${CP} -R gallery ${PREFIX}/www/data

post-install:
	@${ECHO} ""
	@${ECHO} "*****************************************************************"
	@${ECHO} ""
	@${ECHO} " Please consider adding the following 3 lines to your httpd.conf"
	@${ECHO} ""
	@${ECHO} "	<Directory /usr/local/www/data/gallery>"
	@${ECHO} "		AllowOverride Options FileInfo"
	@${ECHO} "	</Directory>"
	@${ECHO} ""
	@${ECHO} " Then restart apache: 'apachectl restart'"
	@${ECHO} ""
	@${ECHO} "*****************************************************************"
	@${ECHO} ""
	@${ECHO} " Please visit 'http://{host.domain}/gallery/' in a"
	@${ECHO} " web-browser and follow the configuration instructions."
	@${ECHO} ""
	@${ECHO} "*****************************************************************"
	@${ECHO} ""

.include <bsd.port.mk>
