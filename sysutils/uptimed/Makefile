# New ports collection makefile for:	uptimed
# Date created:				23 July 2002
# Whom:					Andy Fawcett <andy@athame.co.uk>
#
# $FreeBSD$

PORTNAME=	uptimed
PORTVERSION=	0.3.12
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://podgorny.cz/uptimed/releases/

MAINTAINER=	andy@athame.co.uk
COMMENT=	uptime daemon

USE_RC_SUBR=	${PORTNAME}
USE_LDCONFIG=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		uprecords.1
MAN8=		uptimed.8

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/lib/sendmail|/usr/sbin/sendmail|' ${WRKSRC}/etc/uptimed.conf-dist
	@${REINPLACE_CMD} -e 's|/var/run/uptimed|/var/run/uptimed.pid|' ${WRKSRC}/etc/uptimed.conf-dist

post-install:
	${MKDIR} ${PREFIX}/www/cgi-bin
	${MKDIR} /var/spool/uptimed
	${INSTALL_PROGRAM}	${PREFIX}/bin/uprecords ${PREFIX}/www/cgi-bin/uprecords.cgi
	${INSTALL_DATA}		${WRKSRC}/sample-cgi/* ${PREFIX}/www/cgi-bin/

.include <bsd.port.mk>
