PORTNAME=	kerberos
PORTVERSION=	1.3.1
PORTREVISION=	3
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Kerberos bindings for python
WWW=		https://github.com/apple/ccs-pykerberos

LICENSE=	APACHE20

USES=		python ssl
USE_PYTHON=	autoplist distutils

OPTIONS_DEFAULT=	GSSAPI_BASE
OPTIONS_SINGLE=		GSSAPI
OPTIONS_SINGLE_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT

GSSAPI_BASE_USES=		gssapi
GSSAPI_HEIMDAL_USES=		gssapi:heimdal
GSSAPI_HEIMDAL_EXTRA_PATCHES=	${_HEIMDAL_PATCHES}
GSSAPI_MIT_USES=		gssapi:mit

# Heimdal API (krb5_xfree, krb5_kt_free_entry); upstream targets MIT
_HEIMDAL_PATCHES=	${PATCHDIR}/extra-patch-src_kerberosbasic.h \
			${PATCHDIR}/extra-patch-src_kerberosgss.c \
			${PATCHDIR}/extra-patch-src_kerberosgss.h \
			${PATCHDIR}/extra-patch-src_kerberospw.h

.include <bsd.port.options.mk>

# Base is MIT KRB5 on FreeBSD 15 and later (see Mk/Uses/gssapi.mk)
.if ${PORT_OPTIONS:MGSSAPI_BASE} && !exists(/usr/libdata/pkgconfig/mit-krb5.pc)
EXTRA_PATCHES+=	${_HEIMDAL_PATCHES}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|getoutput("krb5-config|getoutput("${GSSAPIBASEDIR}/bin/krb5-config|g' ${WRKSRC}/setup.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/kerberos*.so

.include <bsd.port.mk>
