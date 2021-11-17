# Created by: Andy Fawcett <andy@athame.co.uk>

PORTNAME=	uptimed
PORTVERSION=	0.4.6
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Uptime daemon

LICENSE=	GPLv2 # only
LICENSE_FILE=	${WRKSRC}/COPYING

#USES=		autoreconf gmake libtool
USES=		autoreconf libtool
USE_GITHUB=	yes
GH_ACCOUNT=	rpodgorny
USE_LDCONFIG=	yes
USE_RC_SUBR=	${PORTNAME}

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/lib/sendmail|/usr/sbin/sendmail| ; \
		 s|/var/run/uptimed|/var/run/uptimed.pid|' \
		${WRKSRC}/etc/uptimed.conf-dist

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
