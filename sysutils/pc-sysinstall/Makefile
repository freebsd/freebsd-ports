# Created by: bms
# $FreeBSD$

PORTNAME=	pc-sysinstall
PORTVERSION=	9.1r${PSVN_REV}
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/bms

MAINTAINER=	josh@ixsystems.com
COMMENT=	PC-BSD system install utility

LICENSE=	BSD

PATCH_STRIP=	-p2
USE_BZIP2=	yes

MAN8=		${PORTNAME}.8
MANCOMPRESSED=	yes

ONLY_FOR_ARCH=	i386 amd64

FSVN_REV=	243808
PSVN_REV=	21630

NO_STAGE=	yes
post-patch:
	${RM} -f ${WRKSRC}/Makefile.inc
	@${REINPLACE_CMD} -e 's|/usr|${LOCALBASE}|g' \
	    ${WRKSRC}/pc-sysinstall/pc-sysinstall.sh

do-build:
	cd ${WRKSRC} && ${MAKE} DESTDIR=${PREFIX} SHAREDIR=/share BINDIR=/sbin MANDIR=/man/man

do-install:
	${MKDIR} ${DATADIR}
	${MKDIR} ${EXAMPLESDIR}
	${MTREE_CMD} -U -d -p ${DATADIR} -f ${FILESDIR}/pc-sysinstall.mtree
	cd ${WRKSRC} && make install DESTDIR=${PREFIX} SHAREDIR=/share BINDIR=/sbin MANDIR=/man/man

.if defined(BOOTSTRAP) || defined(SVN_FETCH)
FETCH_DEPENDS+=		svn:${PORTSDIR}/devel/subversion

FSVNPATH?=	http://svn.freebsd.org/base/release/9.1.0
FSVNDIR=	usr.sbin/pc-sysinstall

PSVNPATH?=	svn://trac.pcbsd.org/pcbsd/branches/9.1
PSVNDIR=	build-files/src-patches
PSVNFILE=	patch-pc-sysinstall-distfiles

do-fetch:
	${MKDIR} ${WRKDIR}
	svn export -r ${FSVN_REV} ${FSVNPATH}/${FSVNDIR} ${WRKDIR}/${DISTNAME}
	#svn export -r ${PSVN_REV} ${PSVNPATH}/${PSVNDIR}/${PSVNFILE} ${WRKDIR}/${PORTNAME}
	cd ${WRKDIR}; tar cvfy ${DISTDIR}/${DISTNAME}.tar.bz2 ${DISTNAME}
.if ${USER} == bmsNOTYET
	scp ${DISTDIR}/${DISTNAME}.tar.bz2 \
	    bms@freefall.freebsd.org:public_distfiles/
.endif
.endif

.include <bsd.port.mk>
