# New ports collection makefile for:   gallery
# Date created:                09 Sep 2001
# Whom:                        Jamie Hermans <jamie@hermans.ca>
#
# $FreeBSD$
#

PORTNAME=	gallery
PORTVERSION=	1.2.5
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	jamie@hermans.ca

RUN_DEPENDS=	${LOCALBASE}/share/netpbm:${PORTSDIR}/graphics/netpbm \
		${LOCALBASE}/bin/jhead:${PORTSDIR}/graphics/jhead

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

do-install:
	${MKDIR} -v ${LOCALBASE}/www/data
	cd ${WRKDIR}; \
		${CP} -R gallery ${LOCALBASE}/www/data

post-install:
	@${ECHO} ""
	@${ECHO} "*****************************************************************"
	@${ECHO} ""
	@${ECHO} " Please consider adding the following 3 lines to your httpd.conf"
	@${ECHO} ""
	@${ECHO} "	<Directory ${LOCALBASE}/www/data/gallery>"
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
