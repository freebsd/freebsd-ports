# New ports collection makefile for:	radmind
# Date created:		2003-11-17
# Whom:			Paul Dlug <paul@aps.org>
#
# $FreeBSD$
#

PORTNAME=	radmind
PORTVERSION=	1.5.0
CATEGORIES=	sysutils
MASTER_SITES=	http://rsug.itd.umich.edu/software/radmind/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	paul@aps.org
COMMENT=	Utility for administering filesystem changes

USE_OPENSSL=	yes
USE_RC_SUBR=	yes

HAS_CONFIGURE=	yes

RADMIND_BASE_DIR?=	/var/radmind

CONFIGURE_ARGS=	--prefix=${PREFIX} --with-radminddir=${RADMIND_BASE_DIR}

MAN1=		fsdiff.1 ktcheck.1 lapply.1 lcksum.1 lcreate.1 lfdiff.1 \
		lmerge.1 twhich.1
MAN5=		applefile.5
MAN8=		radmind.8
DOCS=		COPYRIGHT README SPEC

.include <bsd.port.pre.mk>

RC_SUBR?=				${DESTDIR}/etc/rc.subr
RC_DIR=					${PREFIX}/etc/rc.d
RC_SUFX=				.sh

SED_SCRIPT+=		-e 's,%%RC_SUBR%%,${RC_SUBR},g' \
			-e 's,%%PREFIX%%,${PREFIX},g' \
			-e 's,%%RADMIND_BASE_DIR%%,${RADMIND_BASE_DIR},g' \

PLIST_SUB+=		RC_DIR=${RC_DIR} \
				RC_SUFX=${RC_SUFX} \
				RADMIND_BASE_DIR=${RADMIND_BASE_DIR}

post-build:
	@${SED} ${SED_SCRIPT} ${FILESDIR}/radmind.sh >${WRKDIR}/radmind.sh

post-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/radmind.sh ${RC_DIR}/radmind${RC_SUFX}
	# Ugly hack to remove generated man pages
	${RM} -rf ${WRKSRC}/tmp

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
