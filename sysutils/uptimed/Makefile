# Created by: Andy Fawcett <andy@athame.co.uk>
# $FreeBSD$

PORTNAME=	uptimed
PORTVERSION=	0.4.0
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	pkubaj@anongoth.pl
COMMENT=	Uptime daemon

LICENSE=	GPLv2 # only
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	rpodgorny

USES=		autoreconf gmake libtool tar:bzip2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

USE_RC_SUBR=	${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/lib/sendmail|/usr/sbin/sendmail| ; \
		 s|/var/run/uptimed|/var/run/uptimed.pid|' \
		${WRKSRC}/etc/uptimed.conf-dist
	 @${REINPLACE_CMD} -e \
		's|/etc/uprecords-cgi/|${PREFIX}/www/cgi-bin/|' \
		${WRKSRC}/src/uprecords.c

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/cgi-bin
	${INSTALL_PROGRAM} ${STAGEDIR}${PREFIX}/bin/uprecords \
		${STAGEDIR}${PREFIX}/www/cgi-bin/uprecords.cgi
	${INSTALL_DATA} ${WRKSRC}/sample-cgi/uprecords.conf \
		${STAGEDIR}${PREFIX}/www/cgi-bin/uprecords.conf.sample
	${INSTALL_DATA} ${WRKSRC}/sample-cgi/uprecords.header \
		${STAGEDIR}${PREFIX}/www/cgi-bin/uprecords.header.sample
	${INSTALL_DATA} ${WRKSRC}/sample-cgi/uprecords.footer \
		${STAGEDIR}${PREFIX}/www/cgi-bin/uprecords.footer.sample
	@${MKDIR} ${STAGEDIR}/var/spool/uptimed

.include <bsd.port.mk>
