# Created by: dm
# $FreeBSD$

PORTNAME=	avenger
PORTVERSION=	0.8.5
CATEGORIES=	mail
MASTER_SITES=	http://www.mailavenger.org/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Anti-spam SMTP server

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		bdb ssl

GNU_CONFIGURE=	yes

USERS=		${PORTNAME}
GROUPS=		${USERS}

PORTDOCS=	INSTALL INSTALL.html README NEWS
SUB_FILES=	pkg-message

CONFIGURE_ENV=	WFLAGS='-Wall'
CONFIGURE_ARGS=	--enable-ssl=${OPENSSLBASE} \
		--with-db=${LOCALBASE} \
		--with-etcdir=${ETCDIR}
# Fix build with clang11
CFLAGS+=	-fcommon

OPTIONS_DEFINE=	DOCS SASL

SASL_CONFIGURE_ENABLE=	sasl
SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2

post-patch:
	@${REINPLACE_CMD} -e \
		'/for vers in/s|5.*;|${BDB_LIB_NAME:S,db-,,};|' \
		${WRKSRC}/configure

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

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
