# Created by: Kimo <kimor79@yahoo.com>
# $FreeBSD$

PORTNAME=	mod_auth_cas
PORTVERSION=	1.1
DISTVERSIONPREFIX=	v
CATEGORIES=	www
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache 2.x module that supports the CASv1 and CASv2 protocols

LICENSE=	APACHE20

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libpcre.so:devel/pcre

USE_GITHUB=	yes
GH_ACCOUNT=	Jasig
USES=		apache:2.2+ ssl

HAS_CONFIGURE=	yes
# configure requires LDFLAGS to find libpcre
LDFLAGS+=	-L${AP_LIB}

AP_LIB=		${LOCALBASE}/lib
AP_EXTRAS=	-lpcre -lssl -lcrypto

PLIST_FILES=	@sample\ %%APACHEETCDIR%%/modules.d/%%APMOD_FILE%% \
		%%APACHEMODDIR%%/mod_auth_cas.so

PORTDOCS=	README

SUB_FILES=	${APMOD_FILE}
APMOD_FILE=	250_${PORTNAME}.conf.sample
PLIST_SUB+=	APMOD_FILE=${APMOD_FILE}

.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEMODDIR} ${STAGEDIR}${DOCSDIR}
	${APXS} -S LIBEXECDIR=${STAGEDIR}${PREFIX}/${APACHEMODDIR} \
		-i -n ${MODULENAME} ${WRKSRC}/src/${MODULENAME}.la
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/${MODULENAME}.so
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEETCDIR}/modules.d
	${INSTALL_DATA} ${WRKDIR}/${APMOD_FILE} ${STAGEDIR}${PREFIX}/${APACHEETCDIR}/modules.d
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
