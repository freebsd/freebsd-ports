PORTNAME=	isync
DISTVERSION=	1.5.0
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Maintain local copies of remote IMAP folders w/synchronized flags
WWW=		https://isync.sourceforge.net

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2

USES=		alias compiler:c11 cpe perl5 ssl
CPE_VENDOR=	isync_project
USE_PERL5=	build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-sasl=${LOCALBASE} \
		--with-ssl=${OPENSSLLIB:H}
CONFIGURE_ENV+=	ac_cv_berkdb4=no

MAKE_ARGS+=	SSL_LIBS="-L${OPENSSLLIB} -lssl -lcrypto"

post-patch:
	@${REINPLACE_CMD} -e 's|: install-docDATA|:|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|\$$(docdir)/examples|\$$(sysconfdir)|g' \
	    ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|-Wformat-signedness||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
