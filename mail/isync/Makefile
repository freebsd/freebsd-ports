# Created by: eivind
# $FreeBSD$

PORTNAME=	isync
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Maintain local copies of remote IMAP folders w/synchronized flags

LICENSE=	GPLv2

LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2

USES=		alias cpe
CPE_VENDOR=	oswald_buddenhagen
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-sasl=${LOCALBASE} \
		--with-ssl=${OPENSSLLIB:H}
USE_OPENSSL=	yes
USE_BDB=	46+

CPPFLAGS+=	-I${BDB_INCLUDE_DIR}
LDFLAGS+=	-L${BDB_LIB_DIR}

post-patch:
	@${REINPLACE_CMD} -e 's|: install-docDATA|:|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|\$$(docdir)/examples|\$$(sysconfdir)|g' \
	    ${WRKSRC}/src/Makefile.in ${WRKSRC}/src/compat/Makefile.in
	@${REINPLACE_CMD} -e 's|-ansi||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
