# New ports collection makefile for:	rejik
# Date created:				29 October 2005
# Whom:					Elisey Savateev <b3k@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	rejik
PORTVERSION=	3.2.0
CATEGORIES=	www
MASTER_SITES=	http://www.rejik.ru/download/
DISTNAME=	redirector-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	b3k@mail.ru
COMMENT=	A squid redirector used for blocking unwanted content

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre
RUN_DEPENDS=	squid:${PORTSDIR}/www/squid

USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/redirector

# Redifine this if you need
SQUID_USER?=	squid
SQUID_GROUP?=	squid
WWW_USER?=	www
WWW_GROUP?=	www
WWW_DIR?=	www
WWW_PATH?=	${PREFIX}/${WWW_DIR}
INSTALL_DIR?=	${PORTNAME}
INSTALL_PATH?=	${PREFIX}/${INSTALL_DIR}

PLIST_SUB=	WWW_DIR=${WWW_DIR} INSTALL_DIR=${INSTALL_DIR}
SUB_LIST=	WWW_DIR=${WWW_DIR} INSTALL_DIR=${INSTALL_DIR} SQUID_USER=${SQUID_USER} SQUID_GROUP=${SQUID_GROUP}
SUB_FILES=	pkg-message

OPTIONS=	BAN	"With banlists"	on \
		DBL	"With DBL scripts"	off \
		WWW	"With error pages"	on \

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_BAN)
DISTFILES+=	banlists-2.x.x.tgz
PLIST_SUB+=	BAN=""
.else
PLIST_SUB+=	BAN="@comment "
.endif

.if !defined(WITHOUT_WWW)
DISTFILES+=	squid-like-www-en.tgz
PLIST_SUB+=	WWW=""
.else
PLIST_SUB+=	WWW="@comment "
.endif

.if defined(WITH_DBL)
DISTFILES+=	dbl-2.0.tgz
USE_PERL5_RUN=	yes
RUN_DEPENDS+=	${SITE_PERL}/mach/Text/Iconv.pm:${PORTSDIR}/converters/p5-Text-Iconv \
		${SITE_PERL}/mach/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
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
	@${REINPLACE_CMD} -e 's|SQUID_USER=nobody|SQUID_USER=${SQUID_USER}|; \
		s|SQUID_GROUP=nogroup|SQUID_GROUP=${SQUID_GROUP}|; \
		s|INSTALL_PATH=/usr/local/rejik3|INSTALL_PATH=${INSTALL_PATH}|' \
		${WRKSRC}/Makefile

post-install:
.if !defined(WITHOUT_BAN)
	@${TAR} -xzf ${DISTDIR}/banlists-2.x.x.tgz -C ${INSTALL_PATH}
	@${CHOWN} -R ${SQUID_USER}:${SQUID_GROUP} ${INSTALL_PATH}/banlists
.endif
.if defined(WITH_DBL)
	@${TAR} -xzf ${DISTDIR}/dbl-2.0.tgz -C ${INSTALL_PATH}
	@${CHOWN} -R ${SQUID_USER}:${SQUID_GROUP} ${INSTALL_PATH}/dbl
.endif
.if !defined(WITHOUT_WWW)
	@${TAR} -xzf ${DISTDIR}/squid-like-www-en.tgz -C ${WWW_PATH}
	@${MV} ${WWW_PATH}/squid-like-www-en ${WWW_PATH}/ban
	@${CHOWN} -R ${WWW_USER}:${WWW_GROUP} ${WWW_PATH}/ban
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
