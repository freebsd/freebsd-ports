PORTNAME=	radmind
DISTVERSION=	1.16.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/voretaq7/${PORTNAME}/releases/download/${PORTNAME}-${DISTVERSION}/

MAINTAINER=	mikeg@bsd-box.net
COMMENT=	Utility for administering filesystem changes
WWW=		https://github.com/voretaq7/radmind

LICENSE=	Michigan
LICENSE_NAME=	University of Michigan License
LICENSE_FILE=	${WRKSRC}/COPYRIGHT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=	gmake ssl localbase
USE_RC_SUBR=	radmind

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--with-radminddir=${RADMIND_BASE_DIR}

CONFLICTS_INSTALL=	schilyutils # bin/fsdiff

MAKE_JOBS_UNSAFE=	yes

SUB_FILES+=	pkg-install pkg-message
SUB_LIST=	RADMIND_BASE_DIR=${RADMIND_BASE_DIR} RADMINUSER=${RADMINUSER}

USERS=		${RADMINUSER}
GROUPS=		${RADMINUSER}

PLIST_SUB=	RADMIND_BASE_DIR=${RADMIND_BASE_DIR:S@/@@} RADMINUSER=${RADMINUSER}

OPTIONS_DEFINE=		SASL PAM ZLIB DOCS
OPTIONS_DEFAULT=	SASL PAM ZLIB DOCS

PAM_CONFIGURE_ENABLE=	pam

SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
SASL_CONFIGURE_ENABLE=	sasl

ZLIB_CONFIGURE_ENABLE=	zlib

DOCS=		COPYRIGHT SPEC README.md

RADMIND_BASE_DIR?=	${DESTDIR}/var/radmind
RADMINUSER=	radmind

.include <bsd.port.options.mk>

post-install:
	# Ugly hack to remove generated man pages
	${RM} -r ${WRKSRC}/tmp

	# Port's Docs (Copyright & wire protocol info)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

	${MKDIR} ${STAGEDIR}${RADMIND_BASE_DIR}
	${MKDIR} ${STAGEDIR}${RADMIND_BASE_DIR}/cert
	${MKDIR} ${STAGEDIR}${RADMIND_BASE_DIR}/client
	${MKDIR} ${STAGEDIR}${RADMIND_BASE_DIR}/command
	${MKDIR} ${STAGEDIR}${RADMIND_BASE_DIR}/file
	${MKDIR} ${STAGEDIR}${RADMIND_BASE_DIR}/postapply
	${MKDIR} ${STAGEDIR}${RADMIND_BASE_DIR}/preapply
	${MKDIR} ${STAGEDIR}${RADMIND_BASE_DIR}/special
	${MKDIR} ${STAGEDIR}${RADMIND_BASE_DIR}/tmp
	${MKDIR} ${STAGEDIR}${RADMIND_BASE_DIR}/tmp/file
	${MKDIR} ${STAGEDIR}${RADMIND_BASE_DIR}/tmp/transcript
	${MKDIR} ${STAGEDIR}${RADMIND_BASE_DIR}/transcript
	${INSTALL_DATA}    ${FILESDIR}/config.sample ${STAGEDIR}${RADMIND_BASE_DIR}/

.include <bsd.port.mk>
