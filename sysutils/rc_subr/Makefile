# New ports collection makefile for:	rc_subr
# Date created:				July 4, 2003
# Whom:					hetzels@westbend.net
#
# $FreeBSD$
#

PORTNAME=	rc_subr
PORTVERSION=	1.16
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.westbend.net/pub/FreeBSD/ports/local-distfiles/rcNG/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Common startup and shutdown subroutines used by scripts

NO_BUILD=	yes

MAN8=		rc.subr.8
PLIST_FILES=	etc/rc.subr

do-install:
	${INSTALL_DATA} -m 644 ${WRKSRC}/rc.subr ${PREFIX}/etc/
	${INSTALL_MAN} ${WRKSRC}/rc.subr.8 ${PREFIX}/man/man8

.include <bsd.port.pre.mk>
CVS_CMD?=	cvs -z3
CVS_SITES?=	:pserver:anoncvs@anoncvs.FreeBSD.org:/home/ncvs \
		:pserver:anoncvs@anoncvs.de.FreeBSD.org:/home/ncvs \
		:pserver:anoncvs@anoncvs2.de.FreeBSD.org:/home/ncvs \
		:pserver:anoncvs@anoncvs.jp.FreeBSD.org:/home/ncvs

CVS_FILE1=	src/etc/rc.subr
CVS_FILE2=	src/share/man/man8/rc.subr.8
CVS_MANVER=	1.3

#
# CVS checkout stuff mostly stolen from security/openssh-askpass port by
# kris@freebsd.org
#
# NOTE: Don't forget to type 'anoncvs' for password
#
tarball:
	${MKDIR} ${DISTDIR}/${PKGNAME} && \
	cd ${DISTDIR}/${PKGNAME}; \
	for CVS_SITE in ${CVS_SITES}; do \
		${ECHO_MSG} ">> Attempting to check out from $${CVS_SITE}."; \
		if ${CVS_CMD} -d $${CVS_SITE} login ; then \
			if ${CVS_CMD} -d $${CVS_SITE} co -r "${PORTVERSION}" \
			   ${CVS_FILE1}; then \
				${CVS_CMD} -d $${CVS_SITE} co -r ${CVS_MANVER} ${CVS_FILE2}; \
				cd ${DISTDIR}; \
				${ECHO_MSG} ">> Creating dist tarball in ${DISTDIR}"; \
				${ECHO_MSG} ">> \"${PKGNAME}.tar.gz\"."; \
				${MV} ${PKGNAME}/${CVS_FILE1} ${PKGNAME}; \
				${MV} ${PKGNAME}/${CVS_FILE2} ${PKGNAME}; \
				${RM} -rf ${PKGNAME}/src; \
				${TAR}  -czf ${PKGNAME}.tar.gz ${PKGNAME}; \
				exit; \
			fi \
		fi \
	done; \
	${RMDIR} ${DISTDIR}/${PKGNAME}; \
	${ECHO_MSG} ">> CVS checkout failed."; \
	exit 1;

.include <bsd.port.post.mk>
