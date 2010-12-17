# Ports collection makefile for: freeswitch scripts
# Date created: september , 2009
# Whom: Richard Neese <r.neese@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	freeswitch-scripts
PORTVERSION=	201044
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.secure-computing.net/pub/freeswitch/ \
		ftp://ftp2.secure-computing.net/pub/freeswitch/
DISTNAME=	${BASE_PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	${BASE_PORTNAME}

MAINTAINER=	r.neese@gmail.com
COMMENT=	FreeSwitch Scripts

NO_BUILD=	yes
BASE_PORTNAME=	freeswitch
SUB_FILES=	pkg-install

FREESWITCH_USER=	freeswitch
FREESWITCH_GROUP=	${FREESWITCH_USER}

WRKSRC=		${WRKDIR}/${BASE_PORTNAME}-${PORTVERSION}/scripts/

OPTIONS=	JAVASCRIPT	"Install FreeSWITCH JAVASCRIPTS" off \
		PERL		"Install FreeSWITCH Perl Scripts" off \
		PYTHON		"Install FreeSWITCH Python Scripts" off \
		PHP		"Install FreeSWITCH PHP Scripts" off \
		RSS		"Install FreeSWITCH RSS Scripts" off \
		LUA		"Install FreeSWITCH LUA Scripts" off

.include <bsd.port.options.mk>

.for i in JAVASCRIPT PERL PYTHON PHP RSS LUA C
.if !defined(WITH_${i})
PLIST_SUB+=	WITH_${i}="@comment "
.else
PLIST_SUB+=	WITH_${i}=""
.endif
.endfor

pre-install:
	@${SH} ${PKGINSTALL} ${BASE_PORTNAME} PRE-INSTALL

.if ! exists(${PREFIX}/etc/${BASE_PORTNAME}/scripts)
	${MKDIR} ${PREFIX}/etc/${BASE_PORTNAME}/scripts
	${CHOWN} ${FREESWITCH_USER}:${FREESWITCH_GROUP} ${PREFIX}/etc/${BASE_PORTNAME}/scripts
.endif
	${TOUCH} ${PREFIX}/etc/${BASE_PORTNAME}/scripts/.freeswitch-scripts
	${CHOWN} ${FREESWITCH_USER}:${FREESWITCH_GROUP} ${PREFIX}/etc/${BASE_PORTNAME}/scripts/.freeswitch-scripts

do-install:
.if defined(WITH_JAVASCRIPT)
	@${RM} ${WRKSRC}/javascript/ps_pizza.js
	@${RM} ${WRKSRC}/javascript/pizza.js
	@${RM} -rf ${WRKSRC}/javascript/js_modules
	@cd ${WRKSRC}; ${FIND} javascript  \
		| ${CPIO} -pdm -R ${FREESWITCH_USER}:${FREESWITCH_GROUP} ${PREFIX}/etc/${BASE_PORTNAME}/scripts
.endif

.if defined(WITH_PERL)
	@cd ${WRKSRC}; ${FIND} perl \
		| ${CPIO} -pdm -R ${FREESWITCH_USER}:${FREESWITCH_GROUP} ${PREFIX}/etc/${BASE_PORTNAME}/scripts
.endif

.if defined(WITH_PYTHON)
	@cd ${WRKSRC}; ${FIND} python  \
		| ${CPIO} -pdm -R ${FREESWITCH_USER}:${FREESWITCH_GROUP} ${PREFIX}/etc/${BASE_PORTNAME}/scripts

.endif

.if defined(WITH_PHP)
	@cd ${WRKSRC}; ${FIND} php  \
		| ${CPIO} -pdm -R ${FREESWITCH_USER}:${FREESWITCH_GROUP} ${PREFIX}/etc/${BASE_PORTNAME}/scripts
.endif

.if defined(WITH_RSS)
	@cd ${WRKSRC}; ${FIND} rss  \
		| ${CPIO} -pdm -R ${FREESWITCH_USER}:${FREESWITCH_GROUP} ${PREFIX}/etc/${BASE_PORTNAME}/scripts
.endif

.if defined(WITH_LUA)
	@cd ${WRKSRC}; ${FIND} lua  \
		| ${CPIO} -pdm -R ${FREESWITCH_USER}:${FREESWITCH_GROUP} ${PREFIX}/etc/${BASE_PORTNAME}/scripts
.endif

.include <bsd.port.mk>
