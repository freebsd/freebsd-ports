# Created by: edwin@mavetju.org
# $FreeBSD$

PORTNAME=	mod_encoding
PORTVERSION=	20021209
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://webdav.todo.gr.jp/download/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module for non-ASCII filename interoperability

LICENSE=	APACHE11

USE_APACHE=	22+
USES=		iconv gmake
HAS_CONFIGURE=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--bindir=${PREFIX}/bin \
		--sbindir=${PREFIX}/sbin \
		--libexecdir=${APACHEMODDIR} \
		--sysconfdir=${APACHEETCDIR} \
		--includedir=${APACHEINCLUDEDIR} \
		--with-apxs=${APXS}

CONFIGURE_ENV=	PATH="${PREFIX}/bin:${PREFIX}/sbin:${PATH}"
CPPFLAGS+=	-I${APACHEINCLUDEDIR} -I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

EXTRA_PATCHES=	${PATCHDIR}/apache22_patch

.if !defined(WITHOUT_ICONV_FIX)
EXTRA_PATCHES+=	${PATCHDIR}/iconv_hook-20040430.patch
.endif

.if defined(WITH_QUERYSTRING_FIX)
EXTRA_PATCHES+=	${PATCHDIR}/queryfix-patch22
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}
	$(APXS) -S LIBEXECDIR=${STAGEDIR}${PREFIX}/${APACHEMODDIR} \
		-i -n ${MODULENAME} ${WRKSRC}/${MODULENAME}.la
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/${MODULENAME}.so

.include <bsd.port.mk>
