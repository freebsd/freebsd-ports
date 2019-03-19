# Created by: eivind
# $FreeBSD$

PORTNAME=	isync
PORTVERSION=	1.3.0
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Maintain local copies of remote IMAP folders w/synchronized flags

LICENSE=	GPLv2

LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2

USES=		alias bdb cpe perl5 ssl
USE_PERL5=	build

GNU_CONFIGURE=	yes
CPE_VENDOR=	oswald_buddenhagen

CONFIGURE_ARGS=	--with-sasl=${LOCALBASE} \
		--with-ssl=${OPENSSLLIB:H}

MAKE_ARGS+=	SSL_LIBS="-L${OPENSSLLIB} -lssl -lcrypto"

CPPFLAGS+=	-I${BDB_INCLUDE_DIR}
LDFLAGS+=	-L${BDB_LIB_DIR}

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|: install-docDATA|:|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|\$$(docdir)/examples|\$$(sysconfdir)|g' \
	    ${WRKSRC}/src/Makefile.in ${WRKSRC}/src/compat/Makefile.in
	@${REINPLACE_CMD} -e 's|-ansi||g' ${WRKSRC}/${CONFIGURE_SCRIPT}
.if ${ARCH:Mmips*} || ${ARCH:Mpowerpc*} || ${ARCH} == sparc64
	@${REINPLACE_CMD} -e '/pragma/d' ${WRKSRC}/src/util.c
.endif

.include <bsd.port.post.mk>
