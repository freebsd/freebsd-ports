# New ports collection makefile for:    mod_fastcgi ( in apache )
# Date created:         14 Jul 2000
# Whom:                 JunSeon Oh <hollywar@mail.holywar.net>
#
# $FreeBSD$
#

PORTNAME=	mod_fastcgi
PORTVERSION=	2.2.12
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.holywar.net/pub/FreeBSD/ \
		http://www.fastcgi.com/dist/

MAINTAINER=	hollywar@mail.holywar.net

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${APACHE_PORT}
RUN_DEPENDS=	${LOCALBASE}/sbin/apxs:${APACHE_PORT}

APACHE_PORT?=	${PORTSDIR}/www/apache13

do-patch:
	cd ${WRKSRC} ; ${MV} Makefile.tmpl Makefile ;

do-build:
	cd ${WRKSRC} ; ${LOCALBASE}/sbin/apxs -o mod_fastcgi.so -c *.c

do-install:
	cd ${WRKSRC} ; ${LOCALBASE}/sbin/apxs -i -a -n fastcgi mod_fastcgi.so
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/mod_fastcgi
	@cd ${WRKSRC} ; ${CP} -R docs/* ${PREFIX}/share/doc/mod_fastcgi
.endif

post-install:
	@${ECHO_MSG} "*******************************************************"
	@${ECHO_MSG} "* Fast-cgi modules was include with your apache       *"
	@${ECHO_MSG} "* configuration file                                  *"
	@${ECHO_MSG} "*                                                     *"
	@${ECHO_MSG} "* You need to add following line in your apache       *"
	@${ECHO_MSG} "* configuration file. and restart it !                *"
	@${ECHO_MSG} "*                                                     *"
	@${ECHO_MSG} "* AddHandler fastcgi-script fcgi fcgi fpl             *"
	@${ECHO_MSG} "*                                                     *"
	@${ECHO_MSG} "*******************************************************"

.include <bsd.port.mk>
