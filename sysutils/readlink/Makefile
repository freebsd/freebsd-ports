# Created by: dd
# $FreeBSD$

PORTNAME=	readlink
PORTVERSION=	20010616
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/dd

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dereference a symbolic link and print the name of the target

PLIST_FILES=	bin/readlink \
		man/man1/readlink.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/readlink ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/readlink.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

#
# Ports build/install stuff stops here.  Tarball creation stuff begins here.
#
.include <bsd.port.pre.mk>
CVS_CMD?=	cvs -z3
CVS_DATE=	Sun Jun  16 15:58:14 PDT 2001
CVS_SITES?=	anoncvs@anoncvs.openbsd.org:/cvs
CVS_MODULE=	src/usr.bin/readlink

#
# CVS checkout stuff mostly stolen from security/openssh-askpass port by
# kris@freebsd.org
#
tarball:
	@${MKDIR} ${DISTDIR}/${PKGNAME} && \
	cd ${DISTDIR}/${PKGNAME}; \
	for CVS_SITE in ${CVS_SITES}; do \
		${ECHO_MSG} ">> Attempting to check out from $${CVS_SITE}."; \
		if ${CVS_CMD} -d $${CVS_SITE} co -D "${CVS_DATE}" \
		    ${CVS_MODULE}; then \
			cd ${DISTDIR}; \
			${ECHO_MSG} ">> Creating dist tarball in ${DISTDIR}"; \
			${ECHO_MSG} ">> \"${PKGNAME}.tar.gz\"."; \
			${MV} ${PKGNAME}/${CVS_MODULE} \
				${PKGNAME}/${CVS_MODULE:H}/${PKGNAME}; \
			${TAR} -cz \
				-X ${FILESDIR}/tarignore \
				-f ${PKGNAME}.tar.gz \
				-C ${PKGNAME}/${CVS_MODULE:H} \
				${PKGNAME}; \
			exit; \
		fi \
	done; \
	${RMDIR} ${DISTDIR}/${PKGNAME}; \
	${ECHO_MSG} ">> CVS checkout failed."; \
	exit 1;

.include <bsd.port.post.mk>
