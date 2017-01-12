# Created by: Zeus Panchenko <zeus@gnu.org.ua>
# $FreeBSD$

PORTNAME=	mailfromd
PORTVERSION=	8.1
CATEGORIES=	mail
MASTER_SITES=	http://download.gnu.org.ua/pub/release/${PORTNAME}/

MAINTAINER=	zeus@gnu.org.ua
COMMENT=	Mail filtering daemon for Sendmail, Postfix, and MeTA1

LICENSE=	GPLv3+

LIB_DEPENDS=	libmailutils.so:mail/mailutils

USES=		gmake localbase readline tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	DEFAULT_STATE_DIR="${DATABASEDIR}" \
		DEFAULT_SOCKET="unix:${MFD_RUN_DIR}/${PORTNAME}.sock" \
		DEFAULT_USER=mailnull
USE_RC_SUBR=	${PORTNAME}

DATABASEDIR?=	/var/db/${PORTNAME}
MFD_RUN_DIR?=	/var/run/${PORTNAME}

PLIST_SUB+=	DATABASEDIR=${DATABASEDIR} \
		MFD_RUN_DIR=${MFD_RUN_DIR} \
		VERSION=${PORTVERSION}
SUB_LIST+=	MFD_RUN_DIR=${MFD_RUN_DIR}

INFO=		${PORTNAME}
PORTDOCS=	AUTHORS ChangeLog NEWS README THANKS TODO

OPTIONS_DEFINE=		DOCS DSPAM GEOIP NLS
OPTIONS_DEFAULT=	BDB
OPTIONS_MULTI=		DB
OPTIONS_MULTI_DB=	BDB GDBM
OPTIONS_SUB=		yes

BDB_DESC=		Berkeley DB v4.8 support (last working one)
DB_DESC=		Database configuration

DSPAM_DESC=		DSPAM spam filter library support
DSPAM_LIB_DEPENDS=	libdspam.so:mail/dspam
DSPAM_USES=		pkgconfig
DSPAM_CONFIGURE_WITH=	dspam

GEOIP_LIB_DEPENDS=	libGeoIP.so:net/GeoIP
GEOIP_CONFIGURE_WITH=	geoip

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

BDB_USES=		bdb:48
BDB_CONFIGURE_WITH=	berkeley-db
BDB_CPPFLAGS=		-I${BDB_INCLUDE_DIR}
BDB_LDFLAGS=		-L${BDB_LIB_DIR}
INVALID_BDB_VER=	5+

GDBM_LIB_DEPENDS=	libgdbm.so:databases/gdbm
GDBM_CONFIGURE_WITH=	gdbm

post-install:
	@${MKDIR} ${STAGEDIR}${DATABASEDIR} ${STAGEDIR}${MFD_RUN_DIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
