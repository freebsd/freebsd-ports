# Created by: Andy Fawcett <andy@athame.co.uk>
# $FreeBSD$

PORTNAME=	uptimed
PORTVERSION=	0.3.17
CATEGORIES=	sysutils
MASTER_SITES=	http://podgorny.cz/uptimed/releases/ \
		http://www.predatorlabs.net/dl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Uptime daemon

LICENSE=	GPLv2

USE_BZIP2=	yes
USES=		gmake
USE_AUTOTOOLS=	libtoolize aclocal autoheader automake autoconf
LIBTOOLIZE_ARGS=--copy --force
ACLOCAL_ARGS=	# empty
AUTOMAKE_ARGS=	--copy --add-missing --foreign
USE_LDCONFIG=	yes

USE_RC_SUBR=	${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/lib/sendmail|/usr/sbin/sendmail| ; \
		 s|/var/run/uptimed|/var/run/uptimed.pid|' \
		${WRKSRC}/etc/uptimed.conf-dist

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/cgi-bin
	${INSTALL_PROGRAM} ${STAGEDIR}${PREFIX}/bin/uprecords \
		${STAGEDIR}${PREFIX}/www/cgi-bin/uprecords.cgi
	${INSTALL_DATA} ${WRKSRC}/sample-cgi/* \
		${STAGEDIR}${PREFIX}/www/cgi-bin
	@${MKDIR} ${STAGEDIR}/var/spool/uptimed

.include <bsd.port.mk>
