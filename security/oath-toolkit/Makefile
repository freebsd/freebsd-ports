# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	oath-toolkit
PORTVERSION=	2.6.1
CATEGORIES=	security
MASTER_SITES=	SAVANNAH

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Library, tools, and PAM module for OATH authentication

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-html-dir=${DOCSDIR}
USES=		gmake libtool pathfix pkgconfig
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	PSKC DOCS
OPTIONS_DEFAULT=PSKC
OPTIONS_SUB=	yes

PSKC_DESC=	Portable Symmetric Key Container (RFC 6030) support

PSKC_CONFIGURE_ENABLE=	pskc
PSKC_CONFIGURE_ON=	--with-xml-prefix=${LOCALBASE}
PSKC_LIB_DEPENDS=	libxml2.so:textproc/libxml2 \
			libxmlsec1.so:security/xmlsec1

DOCS=		AUTHORS ChangeLog NEWS README

PORTDOCS=	*

post-install:
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}/${DOCSDIR}/
.endfor
	${MKDIR} ${STAGEDIR}/${DOCSDIR}/pam_oath
	${INSTALL_DATA} ${WRKSRC}/pam_oath/README \
		${STAGEDIR}/${DOCSDIR}/pam_oath/

.include <bsd.port.mk>
