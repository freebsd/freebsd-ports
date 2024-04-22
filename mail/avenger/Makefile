PORTNAME=	avenger
PORTVERSION=	0.8.5
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.mailavenger.org/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Anti-spam SMTP server
WWW=		https://www.mailavenger.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		bdb ssl
USE_CXXSTD=	c++14

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--enable-ssl=${OPENSSLBASE} \
		--with-db=${LOCALBASE} \
		--with-etcdir=${ETCDIR}
CONFIGURE_ENV=	WFLAGS='-Wall'

# Fix build with clang11
CFLAGS+=	-fcommon

CONFLICTS_INSTALL=	mailutils # bin/dotlock

SUB_FILES=	pkg-message

USERS=		${PORTNAME}
GROUPS=		${USERS}

PORTDOCS=	INSTALL INSTALL.html README NEWS

OPTIONS_DEFINE=	DOCS SASL

SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
SASL_CONFIGURE_ENABLE=	sasl

post-patch:
	@${REINPLACE_CMD} -e \
		'/for vers in/s|5.*;|${BDB_LIB_NAME:S,db-,,};|' \
		${WRKSRC}/configure

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/asmtpd.conf \
		${STAGEDIR}${ETCDIR}/asmtpd.conf.sample
	${INSTALL_DATA} ${WRKSRC}/etc/unknown \
		${STAGEDIR}${ETCDIR}/unknown.sample
	${INSTALL_DATA} ${WRKSRC}/etc/pf.os ${STAGEDIR}${PREFIX}/share

	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/etc ; ${INSTALL_DATA} smtp-filter.pf avsendmail.m4 \
		${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
