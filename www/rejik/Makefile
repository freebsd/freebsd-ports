# Created by: Elisey Savateev <b3k@mail.ru>
# $FreeBSD$

PORTNAME=	rejik
PORTVERSION=	3.2.11
CATEGORIES=	www
MASTER_SITES=	http://www.rejik.ru/download/ \
		http://bio3k.softboard.ru/uploads/arch/
DISTNAME=	redirector-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	A squid redirector used for blocking unwanted content

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre
RUN_DEPENDS=	squid:${PORTSDIR}/www/squid

PLIST_SUB=	INSTALL_DIR=${INSTALL_DIR}
SUB_LIST=	INSTALL_PATH=${INSTALL_PATH} SQUID_USER=${SQUID_USER} SQUID_GROUP=${SQUID_GROUP}
SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/${DISTNAME}

OPTIONS_DEFINE=	BAN DBL WWW

OPTIONS_DEFAULT=BAN WWW

BAN_DESC=	With banlists
DBL_DESC=	With DBL scripts
WWW_DESC=	With error pages

.include <bsd.port.options.mk>
.include <bsd.port.pre.mk>

# Redifine this if you need
SQUID_USER?=	squid
SQUID_GROUP?=	squid
INSTALL_DIR?=	${PORTNAME}
INSTALL_PATH?=	${PREFIX}/${INSTALL_DIR}

.if ${PORT_OPTIONS:MBAN}
DISTFILES+=	banlists-2.x.x.tgz
PLIST_SUB+=	BAN=""
.else
PLIST_SUB+=	BAN="@comment "
.endif

.if ${PORT_OPTIONS:MWWW}
DISTFILES+=	squid-like-www-en.tgz
PLIST_SUB+=	WWW=""
.else
PLIST_SUB+=	WWW="@comment "
.endif

.if ${PORT_OPTIONS:MDBL}
DISTFILES+=	dbl-2.0.tgz
USE_PERL5_RUN=	yes
RUN_DEPENDS+=	p5-Text-Iconv>=0:${PORTSDIR}/converters/p5-Text-Iconv \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		wget:${PORTSDIR}/ftp/wget
PLIST_SUB+=	DBL=""
.else
PLIST_SUB+=	DBL="@comment "
.endif

post-extract:
	@${ECHO_MSG} "===>  ----------------------------------------------"
	@${ECHO_MSG} "===>  Make sure that squid runs under user squid"
	@${ECHO_MSG} "===>  and group squid. If not, redefine SQUID_USER"
	@${ECHO_MSG} "===>  and SQUID_GROUP."
	@${ECHO_MSG} "===>  ----------------------------------------------"

post-patch:
	@${REINPLACE_CMD} -e 's|nobody|${SQUID_USER}|g; s|nogroup|${SQUID_GROUP}|g; \
		s|/usr/local/rejik3|${INSTALL_PATH}|g' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/usr/local/rejik3|${INSTALL_PATH}|g' \
		${WRKSRC}/vars.h ${WRKSRC}/redirector.conf.dist

post-install:
	@[ -f ${INSTALL_PATH}/redirector.conf ] || \
		${CP} -p ${INSTALL_PATH}/redirector.conf.dist ${INSTALL_PATH}/redirector.conf
.if !defined(WITHOUT_BAN)
.if !exists(${EXAMPLESDIR})
	@${MKDIR} ${EXAMPLESDIR}
.endif
	@${CP} -R ${WRKDIR}/banlists ${EXAMPLESDIR}
.endif
.if defined(WITH_DBL)
	@${REINPLACE_CMD} -e 's|/usr/bin/wget|${LOCALBASE}/bin/wget|g ; \
		s|/usr/local/rejik3|${INSTALL_PATH}|g' \
		${WRKDIR}/dbl/Update ${WRKDIR}/dbl/Update.Fast ${WRKDIR}/dbl/dbl_expand
	@${RM} ${WRKDIR}/dbl/*.bak
	@${CP} ${WRKDIR}/dbl/Update ${WRKDIR}/dbl/Update.dist
	@${CP} ${WRKDIR}/dbl/Update.Fast ${WRKDIR}/dbl/Update.Fast.dist
	@${CP} ${WRKDIR}/dbl/dbl_expand ${WRKDIR}/dbl/dbl_expand.dist
	@${CP} -Rn ${WRKDIR}/dbl ${INSTALL_PATH}
	@${CHOWN} -R ${SQUID_USER}:${SQUID_GROUP} ${INSTALL_PATH}/dbl
	@[ -f ${INSTALL_PATH}/dbl/Update ] || \
		${CP} -p ${INSTALL_PATH}/dbl/Update.dist ${INSTALL_PATH}/dbl/Update
	@[ -f ${INSTALL_PATH}/dbl/Update.Fast ] || \
		${CP} -p ${INSTALL_PATH}/dbl/Update.Fast.dist ${INSTALL_PATH}/dbl/Update.Fast
	@[ -f ${INSTALL_PATH}/dbl/dbl_expand ] || \
		${CP} -p ${INSTALL_PATH}/dbl/dbl_expand.dist ${INSTALL_PATH}/dbl/dbl_expand
.endif
.if !defined(WITHOUT_WWW)
.if !exists(${EXAMPLESDIR})
	@${MKDIR} ${EXAMPLESDIR}
.endif
	@${CP} -R ${WRKDIR}/squid-like-www-en ${EXAMPLESDIR}
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
