# New ports collection makefile for:	uptimed
# Date created:				23 July 2002
# Whom:					Andy Fawcett <andy@athame.co.uk>
#
# $FreeBSD$

PORTNAME=	uptimed
PORTVERSION=	0.2.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	uptimed
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	andy@athame.co.uk

PREFIX=		${LOCALBASE}

INSTALLS_SHLIB=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${LOCALBASE}

USE_GMAKE=	yes

MAN1=		uprecords.1
MAN8=		uptimed.8

post-install:
	${INSTALL_SCRIPT}	${FILESDIR}/uptimed.sh.sample ${PREFIX}/etc/rc.d/
	if [ ! -d "${PREFIX}/www/cgi-bin/" ]; then \
	    ${MKDIR} -p ${PREFIX}/www/cgi-bin; \
	fi
	${INSTALL_PROGRAM}	${PREFIX}/bin/uprecords ${PREFIX}/www/cgi-bin/uprecords.cgi
	${INSTALL_DATA}		${WRKSRC}/sample-cgi/* ${PREFIX}/www/cgi-bin/

.include <bsd.port.mk>
