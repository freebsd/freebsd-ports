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
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtoolize aclocal autoheader automake autoconf
LIBTOOLIZE_ARGS=--copy --force
ACLOCAL_ARGS=	# empty
AUTOMAKE_ARGS=	--copy --add-missing --foreign
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

USE_RC_SUBR=	${PORTNAME}

MAN1=		uprecords.1
MAN8=		uptimed.8

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/lib/sendmail|/usr/sbin/sendmail| ; \
		 s|/var/run/uptimed|/var/run/uptimed.pid|' \
		${WRKSRC}/etc/uptimed.conf-dist

post-install:
	@${MKDIR} ${PREFIX}/www/cgi-bin
	(cd ${PREFIX}/bin && ${INSTALL_PROGRAM} uprecords \
		${PREFIX}/www/cgi-bin/uprecords.cgi)
	(cd ${WRKSRC}/sample-cgi && ${INSTALL_DATA} * \
		${PREFIX}/www/cgi-bin)
	@${MKDIR} /var/spool/uptimed

.include <bsd.port.mk>
