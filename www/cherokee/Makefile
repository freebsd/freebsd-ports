# New ports collection makefile for:	cherokee
# Date created:			01 Jun 2002
# Whom:				silence <oksala@videotron.ca>
#
# $FreeBSD$
#

PORTNAME=	Cherokee
PORTVERSION=	0.2.8
CATEGORIES=	www
MASTER_SITES=	http://www.alobbs.com/cherokee/

MAINTAINER=	oksala@videotron.ca
COMMENT=	Cherokee is an extremely fast and tiny web server

USE_AUTOCONF=	yes
USE_AUTOMAKE=	yes
HAS_CONFIGURE=  yes
CONFIGURE_ARGS+=	\
		--prefix=${PREFIX} \
		--enable-daemon\
		--enable-warnings\
		--with-htdocs=${HTDOCS}\
		--with-uid=${UID} \
		--with-gid=${GID} \
		--with-port=${PORT} \
		--with-index=${INDEX}


#
# User Configuration
# This may seem a little overloaded
# But there is not configuration files or getopt options
#

#User Configurations
#Dir for your html files
.if defined(HTDOCS)
HTDOCS=${HTDOCS}
.else
HTDOCS=${PREFIX}/www/data
.endif

#Process UID
.if defined(USER_ID)
USER_ID=${USER_ID}
.else
USER_ID=80      #www
.endif

#Process GID
.if defined(GROUP_ID)
GROUP_ID=${GROUP_ID}
.else
GROUP_ID=80     #www
.endif

#inet port
.if defined(PORT)
PORT=${PORT}
.else
PORT=80
.endif

#index files
.if defined(INDEX)
INDEX=${INDEX}
.else
INDEX=index.html
.endif

pre-configure:
	@${ECHO} ""
	@${ECHO} "=================================="
	@${ECHO} ""
	@${ECHO} "Current configuration :"
	@${ECHO} "Working directory : ${HTDOCS} (HTDOCS)"
	@${ECHO} "Process id : ${USER_ID} (USER_ID)"
	@${ECHO} "Process gid : ${GROUP_ID} (GROUP_ID)"
	@${ECHO} "Inet port : ${PORT} (PORT)"
	@${ECHO} "Index files : ${INDEX} (INDEX)"
	@${ECHO} ""
	@${ECHO} "=================================="
	@${ECHO} ""

pre-install:
	@if [ ! -f ${PREFIX}/www ]; then \
		${MKDIR} ${PREFIX}/www;\
	fi
	@if [ ! -f ${HTDOCS} ] ; then \
		${MKDIR} ${HTDOCS};\
	fi

.include <bsd.port.mk>
