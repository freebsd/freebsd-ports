PORTNAME=	shuffle
PORTVERSION=	20010603
CATEGORIES=	misc
MASTER_SITES=	LOCAL/dd

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Produce random permutations

PLIST_FILES=	bin/shuffle man/man1/shuffle.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/shuffle ${STAGEDIR}${PREFIX}/bin/shuffle
	${INSTALL_MAN} ${WRKSRC}/shuffle.1.gz ${STAGEDIR}${PREFIX}/man/man1

#
# Ports build/install stuff stops here.  Tarball creation stuff begins here.
#
.include <bsd.port.pre.mk>
CVS_CMD?=	cvs -z3
CVS_DATE=	Sun Jun  3 15:58:14 PDT 2001
CVS_SITES?=	anoncvs@anoncvs.netbsd.org:/cvsroot
CVS_MODULE=	basesrc/usr.bin/shuffle

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
