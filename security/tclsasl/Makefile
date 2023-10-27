PORTNAME=	tclsasl
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	security tcl
MASTER_SITES=	http://beepcore-tcl.sourceforge.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tcl interface to the Cyrus SASLv2 library
WWW=		https://beepcore-tcl.sourceforge.net/tclsasl.html

LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2

USES=		tcl:tea libtool tar:tgz
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--with-cyrus-sasl=${LOCALBASE}
CONFIGURE_ENV=	INSTALL="${INSTALL_DATA}" STAGEDIR="${STAGEDIR}" \
			CPPFLAGS="${CPPFLAGS}"

PORTDOCS=	tclsasl.html

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400091
CPPFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/tclsasl.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
