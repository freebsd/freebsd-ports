# New ports collection makefile for:	mod_pcgi2
# Date created:		19 May 2002
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	mod_pcgi2
PORTVERSION=	2.0.1
CATEGORIES=	www zope
MASTER_SITES=	http://www.zope.org/Members/phd/mod_pcgi2/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	perky@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/${SZOPEBASEDIR}/z2.py:${PORTSDIR}/www/zope

.if defined(WITH_APACHE13)
BUILD_DEPENDS=	${LOCALBASE}/include/apache/httpd.h:${PORTSDIR}/www/apache13
RUN_DEPENDS=	${LOCALBASE}/include/apache/httpd.h:${PORTSDIR}/www/apache13
.else
BUILD_DEPENDS=	${LOCALBASE}/include/apache2/httpd.h:${PORTSDIR}/www/apache2
RUN_DEPENDS=	${LOCALBASE}/include/apache2/httpd.h:${PORTSDIR}/www/apache2
.endif

USE_PYTHON=	yes

# You can change this in the environment if you like.
SZOPEBASEDIR?=	www/Zope
APXS?=		${LOCALBASE}/sbin/apxs

# Don't change these
ZOPEBASEDIR=	${LOCALBASE}/${SZOPEBASEDIR}
WRKSRC=		${WRKDIR}/pcgi2
BUILDOPT=	-DMOD_PCGI2 -DUNIX -DHAVE_UNION_SEMUN
SOURCES=	mod_pcgi2.c parseinfo.c pcgi-wrapper.c
PLIST_SUB=	APXS="${APXS}" APACHEVER="${APACHEVER}"
MSG_SUB=	-e 's,%%CONFFILE%%,etc/${APACHEVER}/mod_pcgi2.conf,' \
		-e 's,%%PREFIX%%,${PREFIX},'
PKGMESSAGE=	${WRKDIR}/pkg-message

.if defined(WITH_APACHE13)
APACHEVER=	apache
.else
APACHEVER=	apache2
BUILDOPT+=	-DAPACHE2 -Wc,-shared
.endif

post-extract:
	@${SED} -e 's,%%PYTHON_CMD%%,${PYTHON_CMD},g' \
		-e 's,%%ZOPEBASEDIR%%,${ZOPEBASEDIR},g' \
		${FILESDIR}/mod_pcgi2.conf.dist >${WRKDIR}/mod_pcgi2.conf
	@${SED} ${MSG_SUB} pkg-message > ${PKGMESSAGE}

do-build:
	@cd ${WRKSRC} && ${APXS} -c -o mod_pcgi2.so ${BUILDOPT} ${SOURCES}

do-install:
.if defined(WITH_APACHE13)
	@${APXS} -ia -n pcgi2 ${WRKSRC}/mod_pcgi2.so
.else
	@${INSTALL_PROGRAM} ${WRKSRC}/mod_pcgi2.so ${PREFIX}/libexec/${APACHEVER}/
	@${APXS} -ea -n pcgi2 libexec/${APACHEVER}/mod_pcgi2.so
.endif
	@${INSTALL_DATA} ${WRKDIR}/mod_pcgi2.conf ${PREFIX}/etc/${APACHEVER}/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
