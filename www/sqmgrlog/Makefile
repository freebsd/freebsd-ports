# New ports collection makefile for:	sqmgrlog
# Date created:		Mon Feb  5 17:00:40 NOVT 2001
# Whom:			Dmitry Grigorovich <odip@bionet.nsc.ru>
#
# $FreeBSD$
#

PORTNAME=	sqmgrlog
PORTVERSION=	3.0.1
CATEGORIES=	www
MASTER_SITES=	http://web.onda.com.br/orso/

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-prefix=${PREFIX} --with-gcc

post-patch:
	@${REINPLACE_CMD} -e 's,LDFLAGS="-g",LDFLAGS="",' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,/usr/local/etc/httpd/htdocs/,${PREFIX}/www/data/,; \
		s,mailx,mail,' ${WRKSRC}/sqmgrlog.conf ${WRKSRC}/log.c

post-install:
	@if [ ! -f ${PREFIX}/etc/sqmgrlog.conf ]; then \
		${INSTALL_DATA} ${WRKSRC}/sqmgrlog.conf ${PREFIX}/etc; \
	fi

.include <bsd.port.mk>
