# New ports collection makefile for:	uptimed
# Date created:				23 July 2002
# Whom:					Andy Fawcett <andy@athame.co.uk>
#
# $FreeBSD$

PORTNAME=	uptimed
PORTVERSION=	0.3.3
CATEGORIES=	sysutils
MASTER_SITES=	http://unixcode.org/downloads/uptimed/ \
		http://people.fruitsalad.org/tap/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	andy@athame.co.uk
COMMENT=	Rob Kaper's uptime daemon

PREFIX=		${LOCALBASE}

USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${LOCALBASE}

USE_GMAKE=	yes

MAN1=		uprecords.1
MAN8=		uptimed.8

post-install:
	${INSTALL_SCRIPT}	${FILESDIR}/uptimed.sh.sample ${PREFIX}/etc/rc.d/
	if [ ! -d "${PREFIX}/www/cgi-bin/" ]; then \
	    ${MKDIR} ${PREFIX}/www/cgi-bin; \
	fi
	${INSTALL_PROGRAM}	${PREFIX}/bin/uprecords ${PREFIX}/www/cgi-bin/uprecords.cgi
	${INSTALL_DATA}		${WRKSRC}/sample-cgi/* ${PREFIX}/www/cgi-bin/

.include <bsd.port.mk>
