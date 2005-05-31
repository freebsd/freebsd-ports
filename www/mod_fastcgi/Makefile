# New ports collection makefile for:    mod_fastcgi ( in apache )
# Date created:         14 Jul 2000
# Whom:                 JunSeon Oh <hollywar@mail.holywar.net>
#
# $FreeBSD$
#

PORTNAME=	mod_fastcgi
PORTVERSION=	2.4.2
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.holywar.net/pub/FreeBSD/ \
		http://www.fastcgi.com/dist/

MAINTAINER=	hollywar@mail.holywar.net
COMMENT=	A fast-cgi module for Apache

BUILD_DEPENDS=	${APXS}:${PORTSDIR}/${APACHE_PORT}

CONFLICTS=	apache-contrib-1.*

.if defined(WITH_APACHE2)
MAKEFILE=	Makefile.AP2
USE_REINPLACE=	YES
MAKE_ARGS=	INCLUDES=-I${PREFIX}/include/apache2
INSTALL_TARGET=	install-modules
PLIST_SUB=	APACHE=2
.else
PLIST_SUB=	APACHE=
.endif

.if defined(WITHOUT_APACHE_SUEXEC)
APXSOPTS+=	-DNO_SUEXEC_FOR_AP_USER_N_GROUP
.endif

do-patch:
.if defined(WITH_APACHE2)
	@${REINPLACE_CMD} -e "s|/usr/local/apache2|${PREFIX}/share/apache2|g" ${WRKSRC}/${MAKEFILE}
.else
	cd ${WRKSRC} ; ${MV} Makefile.tmpl Makefile ;

do-build:
	cd ${WRKSRC} ; ${LOCALBASE}/sbin/apxs -o mod_fastcgi.so -c ${APXSOPT} *.c

do-install:
	cd ${WRKSRC} ; ${LOCALBASE}/sbin/apxs -i -a -n fastcgi mod_fastcgi.so
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in LICENSE.TERMS mod_fastcgi.html
	${INSTALL_DATA} ${WRKSRC}/docs/${file} ${DOCSDIR}
.endfor
.endif

	@${ECHO_MSG} "************************************************************"
.if !defined(WITH_APACHE2)
	@${ECHO_MSG} "* Fast-cgi modules was included with your apache           *"
	@${ECHO_MSG} "* configuration file                                       *"
	@${ECHO_MSG} "*                                                          *"
.endif
	@${ECHO_MSG} "* You need to add following lines to your apache           *"
	@${ECHO_MSG} "* configuration file. and restart it !                     *"
	@${ECHO_MSG} "*                                                          *"
.if defined(WITH_APACHE2)
	@${ECHO_MSG} "* LoadModule fastcgi_module libexec/apache2/mod_fastcgi.so *"
.endif
	@${ECHO_MSG} "* AddHandler fastcgi-script fcgi fcgi fpl                  *"
	@${ECHO_MSG} "*                                                          *"
	@${ECHO_MSG} "************************************************************"

.include <bsd.port.mk>
