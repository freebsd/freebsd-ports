# New ports collection makefile for:	radmind
# Date created:		2003-11-17
# Whom:			Paul Dlug <paul@aps.org>
#
# $FreeBSD$
#

PORTNAME=	radmind
PORTVERSION=	1.6.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	paul@aps.org
COMMENT=	Utility for administering filesystem changes

USE_OPENSSL=	yes
USE_RC_SUBR=	radmind.sh
SUB_LIST=	RADMIND_BASE_DIR=${RADMIND_BASE_DIR}
PLIST_SUB=	RADMIND_BASE_DIR=${RADMIND_BASE_DIR}

HAS_CONFIGURE=	yes

RADMIND_BASE_DIR?=	/var/radmind

CONFIGURE_ARGS=	--prefix=${PREFIX} --with-radminddir=${RADMIND_BASE_DIR}

MAN1=		fsdiff.1 ktcheck.1 lapply.1 lcksum.1 lcreate.1 lfdiff.1 \
		lmerge.1 lsort.1 twhich.1 rash.1
MAN5=		applefile.5
MAN8=		radmind.8
DOCS=		COPYRIGHT README SPEC

post-install:
	# Ugly hack to remove generated man pages
	${RM} -rf ${WRKSRC}/tmp

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
