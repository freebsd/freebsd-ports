# Ports collection makefile for:  cvsync
# Date created:			  Thu Mar 6, 2003
# Whom:				  Hiroki Sato <hrs@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cvsync
PORTVERSION=	0.24.16
PORTREVISION=	1
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.cvsync.org/pub/cvsync/ \
		ftp://ftp.allbsd.org/pub/cvsync/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A portable CVS repository synchronization utility

USE_GMAKE=	yes
USE_RC_SUBR=	yes

MAN1=		cvscan.1 cvsup2cvsync.1 cvsync.1 cvsync2cvsup.1 cvsyncd.1 \
		rcscan.1 rcscmp.1
DOCS=		doc/COPYRIGHT doc/ChangeLog doc/FAQ doc/TODO
EXAMPLES=	samples/cvsync.conf samples/cvsyncd-FreeBSD.conf \
		samples/cvsyncd-NetBSD.conf samples/cvsyncd-OpenBSD.conf
STARTUPDIR=	etc/rc.d
STARTUPFILES=	cvsyncd.sh

MAKE_ENV+=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" PTHREAD_LIBS="${PTHREAD_LIBS}"
MAKE_FLAGS=	OSVER="${OSVERSION}"

.if !defined(WITHOUT_OPENSSL)
USE_OPENSSL=	yes
MAKE_FLAGS+=	HASH_TYPE=openssl
.endif
PLIST_SUB=	STARTUPDIR=${STARTUPDIR}
RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

post-install:
.for file in ${STARTUPFILES}
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/${file} > ${WRKDIR}/${file}
	${INSTALL_SCRIPT} ${WRKDIR}/${file} ${PREFIX}/${STARTUPDIR}/${file}
.endfor
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
