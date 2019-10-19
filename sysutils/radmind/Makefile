# Created by: Paul Dlug <paul@aps.org>
# $FreeBSD$

PORTNAME=	radmind
PORTVERSION=	1.15.1
PORTREVISION=	2019101801
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/voretaq7/${PORTNAME}/releases/download/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	mikeg@bsd-box.net
COMMENT=	Utility for administering filesystem changes

LICENSE=	Michigan
LICENSE_NAME=	University of Michigan License
LICENSE_FILE=	${WRKSRC}/COPYRIGHT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=	ssl
USE_RC_SUBR=	radmind
MAKE_JOBS_UNSAFE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-radminddir=${RADMIND_BASE_DIR}

RADMINUSER=	radmind
USERS=		${RADMINUSER}
GROUPS=		${RADMINUSER}
RADMIND_BASE_DIR?=	/var/radmind

SUB_LIST=	RADMIND_BASE_DIR=${RADMIND_BASE_DIR} RADMINUSER=${RADMINUSER}
PLIST_SUB=	RADMIND_BASE_DIR=${RADMIND_BASE_DIR:S@/@@} RADMINUSER=${RADMINUSER}
SUB_FILES+=	pkg-install pkg-message

DOCS=		COPYRIGHT SPEC README.md

OPTIONS_DEFINE=	DOCS

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
	${CP}    ${FILESDIR}/config.sample ${STAGEDIR}${RADMIND_BASE_DIR}/config.sample

.include <bsd.port.mk>
