# New ports collection makefile for:	cherokee
# Date created:			01 Jun 2002
# Whom:				silence <oksala@videotron.ca>
#
# $FreeBSD$
#

PORTNAME=	cherokee
PORTVERSION=	0.4.2
CATEGORIES=	www
MASTER_SITES=	ftp://www.alobbs.com/cherokee/

MAINTAINER=	oksala@videotron.ca
COMMENT=	Cherokee is an extremely fast and tiny web server

#USE_AUTOCONF_VER=213
#USE_AUTOMAKE_VER=14
HAS_CONFIGURE=  yes
CONFIGURE_ARGS= --prefix=${PREFIX}
INSTALLS_SHLIB=	yes

#This is experimental
#do not expect it to work properly
.if defined(WITH_PHP)
CONFIGURE_ARGS+=--with-php=${PREFIX}/include/php
BUILD_DEPENDS=mod_php4:${PORTSDIR}/www/mod_php4:
.endif

MAN1=		cherokee.1

#pre-everything:
#	@${ECHO_MSG} "----------------------------"
#	@${ECHO_MSG} " "
#	@${ECHO_MSG} "You can add php support"
#	@${ECHO_MSG} "This is experimental"
#	@${ECHO_MSG} "builds cherokee with WITH_PHP=yes"
#	@${ECHO_MSG} "For example,"
#	@${ECHO_MSG} "make WITH_PHP=yes"
#	@${ECHO_MSG} " "
#	@${ECHO_MSG} "----------------------------"

pre-install:
	@if [ ! -f ${PREFIX}/www ]; then \
		${MKDIR} ${PREFIX}/www;\
	fi
	@if [ ! -f ${PREFIX}/www/data ] ; then \
		${MKDIR} ${PREFIX}/www/data;\
	fi
	@${ECHO_MSG} " `pwd` "

post-install:
	@${INSTALL}  -m 644 ${WRKSRC}/doc/Intro.txt ${PREFIX}/share/cherokee
	@${ECHO_MSG} " "
	@${ECHO_MSG} " Dont forget to read the doc "
	@${ECHO_MSG} " ${PREFIX}/share/cherokee/Intro.txt"
	@${ECHO_MSG} " "

.include <bsd.port.mk>
