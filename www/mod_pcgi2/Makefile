# New ports collection makefile for:	mod_pcgi2
# Date created:		19 May 2002
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	mod_pcgi2
PORTVERSION=	2.0.2
CATEGORIES=	www zope
MASTER_SITES=	http://zope.org/Members/phd/mod_pcgi2/mod_pcgi2/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Persistent CGI module for Apache and Zope

RUN_DEPENDS=	${ZOPEBASEDIR}/skel/bin/zopectl.in:${PORTSDIR}/www/zope

BROKEN=		Does not install

.if defined(WITH_APACHE13)
BUILD_DEPENDS=	${LOCALBASE}/include/apache/httpd.h:${PORTSDIR}/${APACHE_PORT}
RUN_DEPENDS=	${LOCALBASE}/include/apache/httpd.h:${PORTSDIR}/${APACHE_PORT}
.else
BUILD_DEPENDS=	${LOCALBASE}/include/apache2/httpd.h:${PORTSDIR}/${APACHE_PORT}
RUN_DEPENDS=	${LOCALBASE}/include/apache2/httpd.h:${PORTSDIR}/${APACHE_PORT}
.endif

USE_PYTHON=	yes

# You can change this in the environment if you like.
SZOPEBASEDIR?=	www/Zope

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
WITH_APACHE2=	yes
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
