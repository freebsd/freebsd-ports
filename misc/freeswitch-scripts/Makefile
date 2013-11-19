# Created by: Richard Neese <r.neese@gmail.com>
# $FreeBSD$

PORTNAME=	freeswitch-scripts
PORTVERSION=	1.0.7.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	misc
MASTER_SITES=	http://dl.dropbox.com/u/152504/
DISTNAME=	${BASE_PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	${BASE_PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FreeSwitch Scripts

DEPRECATED=	Depends on expired net/freeswitch-core
EXPIRATION_DATE=2013-12-19

RUN_DEPENDS=    ${LOCALBASE}/bin/freeswitch:${PORTSDIR}/net/freeswitch-core

CONFLICTS=	freeswitch-scripts-devel-[0-9]*

NO_BUILD=	yes
BASE_PORTNAME=	freeswitch
SUB_FILES=	pkg-install

FREESWITCH_USER=	freeswitch
FREESWITCH_GROUP=	${FREESWITCH_USER}

WRKSRC=		${WRKDIR}/${BASE_PORTNAME}-${PORTVERSION}/scripts/

OPTIONS_DEFINE=	JAVASCRIPT PERL PYTHON PHP RSS LUA
JAVASCRIPT_DESC=	Javascript scripting language
RSS_DESC=	RSS scripts

NO_STAGE=	yes
.include <bsd.port.options.mk>

.for i in JAVASCRIPT PERL PYTHON PHP RSS LUA C
.if ${PORT_OPTIONS:M${i}}
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
.if ${PORT_OPTIONS:MJAVASCRIPT}
	@${RM} ${WRKSRC}/javascript/ps_pizza.js
	@${RM} ${WRKSRC}/javascript/pizza.js
	@${RM} -rf ${WRKSRC}/javascript/js_modules
	@cd ${WRKSRC}; ${FIND} javascript  \
		| ${CPIO} -pdm -R ${FREESWITCH_USER}:${FREESWITCH_GROUP} ${PREFIX}/etc/${BASE_PORTNAME}/scripts
.endif

.if ${PORT_OPTIONS:MPERL}
	@cd ${WRKSRC}; ${FIND} perl \
		| ${CPIO} -pdm -R ${FREESWITCH_USER}:${FREESWITCH_GROUP} ${PREFIX}/etc/${BASE_PORTNAME}/scripts
.endif

.if ${PORT_OPTIONS:MPYTHON}
	@cd ${WRKSRC}; ${FIND} python  \
		| ${CPIO} -pdm -R ${FREESWITCH_USER}:${FREESWITCH_GROUP} ${PREFIX}/etc/${BASE_PORTNAME}/scripts

.endif

.if ${PORT_OPTIONS:MPHP}
	@cd ${WRKSRC}; ${FIND} php  \
		| ${CPIO} -pdm -R ${FREESWITCH_USER}:${FREESWITCH_GROUP} ${PREFIX}/etc/${BASE_PORTNAME}/scripts
.endif

.if ${PORT_OPTIONS:MRSS}
	@cd ${WRKSRC}; ${FIND} rss  \
		| ${CPIO} -pdm -R ${FREESWITCH_USER}:${FREESWITCH_GROUP} ${PREFIX}/etc/${BASE_PORTNAME}/scripts
.endif

.if ${PORT_OPTIONS:MLUA}
	@cd ${WRKSRC}; ${FIND} lua  \
		| ${CPIO} -pdm -R ${FREESWITCH_USER}:${FREESWITCH_GROUP} ${PREFIX}/etc/${BASE_PORTNAME}/scripts
.endif

.include <bsd.port.mk>
