# New ports collection makefile for:	radmind
# Date created:		2003-11-17
# Whom:			Paul Dlug <paul@aps.org>
#
# $FreeBSD$
#

PORTNAME=	radmind
PORTVERSION=	1.14.1
PORTREVISION=	2012032001
CATEGORIES=	sysutils
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	mikeg@bsd-box.net
COMMENT=	Utility for administering filesystem changes

USE_OPENSSL=	yes
USE_RC_SUBR=	radmind
MAKE_JOBS_UNSAFE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-radminddir=${RADMIND_BASE_DIR}

RADMINUSER=	radmind
USERS=		${RADMINUSER}
GROUPS=		${RADMINUSER}
RADMIND_BASE_DIR?=	/var/radmind

SUB_LIST=	RADMIND_BASE_DIR=${RADMIND_BASE_DIR} RADMINUSER=${RADMINUSER}
PLIST_SUB=	RADMIND_BASE_DIR=${RADMIND_BASE_DIR} RADMINUSER=${RADMINUSER}
SUB_FILES+=	pkg-install pkg-message

MAN1=		fsdiff.1 ktcheck.1 lapply.1 lcksum.1 lcreate.1 lfdiff.1 \
		lmerge.1 lsort.1 twhich.1 rash.1 repo.1
MAN5=		applefile.5
MAN8=		radmind.8
DOCS=		COPYRIGHT README SPEC

OPTIONS=	IGNORE_TIMESTAMPS	"Add '-t' option to fsdiff"	Off

.include <bsd.port.options.mk>

.if defined(WITH_IGNORE_TIMESTAMPS)
EXTRA_PATCHES+=	${FILESDIR}/optpatch-ignore_timestamps
.endif

post-install:
# Ugly hack to remove generated man pages
	${RM} -rf ${WRKSRC}/tmp

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
	${CP} ${FILESDIR}/config.sample ${RADMIND_BASE_DIR}/config.sample
	@if [ ! -f ${RADMIND_BASE_DIR}/config ]; then \
		${CP} -p ${RADMIND_BASE_DIR}/config.sample ${RADMIND_BASE_DIR}/config ; \
	fi
	@${CHOWN} -R ${RADMINUSER}:${RADMINUSER} ${RADMIND_BASE_DIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
