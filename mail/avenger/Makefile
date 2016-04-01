# Created by: dm
# $FreeBSD$

PORTNAME=	avenger
PORTVERSION=	0.8.4
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.mailavenger.org/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Anti-spam SMTP server

LICENSE=	GPLv2+ # though COPYING is GPLv3

USE_BDB=	42+
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes

USERS=		${PORTNAME}
GROUPS=		${USERS}

PORTDOCS=	INSTALL INSTALL.html README NEWS
SUB_FILES=	pkg-message

CONFIGURE_ENV=	WFLAGS='-Wall'
CONFIGURE_ARGS=	--enable-ssl=${OPENSSLBASE} \
		--with-db=${LOCALBASE} \
		--with-etcdir=${ETCDIR}

OPTIONS_DEFINE=	SASL DOCS

SASL_CONFIGURE_ON=	--enable-sasl
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
	${INSTALL_DATA} ${WRKSRC}/etc/smtp-filter.pf ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/etc/avsendmail.m4 ${STAGEDIR}${DATADIR}

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
