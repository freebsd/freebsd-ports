# New ports collection makefile for: sword
# Date created:   22 may 2001
# Whom:           Willem van Engen <wvengen@stack.nl>
#
# $FreeBSD$
#

PORTNAME=	sword
PORTVERSION=	1.5.3
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.crosswire.org/pub/sword/source/v1.5/ \
		http://www.crosswire.org/sword/download/ftpmirror/pub/sword/source/v1.5/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	wvengen@stack.nl

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--program-transform-name=""

post-install: register
.if !exists(${PREFIX}/etc/sword.conf)
	@${ECHO_CMD} "[Install]" >${PREFIX}/etc/sword.conf
	@${ECHO_CMD} "DataPath=${DATADIR}" >>${PREFIX}/etc/sword.conf
	@${ECHO_CMD} "Config file installed in ${PREFIX}/etc/sword.conf"
.else
	@${ECHO_CMD} "Config file not installed since ${PREFIX}/etc/sword.conf already exists."
	@${ECHO_CMD} "Please check that DataPath points to your modules (default ${DATADIR}).";
.endif
	@${ECHO_CMD} ""
	@${CAT} ${PKGMESSAGE}

register:
.if !defined(BATCH)
	@${ECHO} "Do you want to help the authors of SWORD to keep track of how many"
	@${ECHO} -n "people use this program and register now ? [y/n] "
	@read answer; \
	 if [ x$$answer = xy -o x$$answer = xY ]; then \
		(cd ${WRKSRC}; ${GMAKE} register;); \
	 fi
.endif

.include <bsd.port.mk>
