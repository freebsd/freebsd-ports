# $FreeBSD$

PORTNAME=	stf
PORTVERSION=	0.${SVN_REV}
CATEGORIES=	net ipv6
MASTER_SITES=	LOCAL/kuriyama
PKGNAMESUFFIX=	-6rd-kmod
DISTNAME=	freebsd-stf-${OSREL}-${PORTVERSION}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	6rd patched stf(4) kernel modules port for 8.4+

ONLY_FOR_ARCHS=	amd64 i386

WRKSRC=		${WRKDIR}
SVN_REV=	275558
PATCH_STRIP=	-p1
#PATCH_DEBUG=	YES

USES=		kmod

.include <bsd.port.pre.mk>

.if ${OSREL} == "8.4"
PATCHDIR=	${MASTERDIR}/files-8
.elif ${OSREL} == "9.1"
PATCHDIR=	${MASTERDIR}/files-9.1
.elif ${OSREL} == "9.3"
PATCHDIR=	${MASTERDIR}/files-9
.elif ${OSREL} == "10.1"
PATCHDIR=	${MASTERDIR}/files-10
.else
IGNORE=		not supported $${OSREL} (${OSREL})
.endif

post-extract:
	cd ${WRKSRC} && ${MKDIR} tmp && ${MV} net modules tmp/
	${CP} -Rp ${SRC_BASE}/sys ${WRKSRC}/
	${MKDIR} ${WRKSRC}/share/man
	${CP} -Rp ${SRC_BASE}/share/man/man4 ${WRKSRC}/share/man/
	${CP} -Rp ${WRKSRC}/tmp/* ${WRKSRC}/sys/

do-build:
	cd ${WRKSRC}/sys/modules/if_stf; ${MAKE} DEBUG_FLAGS=-g

do-install:
.for f in if_stf
	${INSTALL_KLD} ${WRKSRC}/sys/modules/if_stf/${f}.ko ${STAGEDIR}${KMODDIR}
	${INSTALL_KLD} ${WRKSRC}/sys/modules/if_stf/${f}.ko.symbols ${STAGEDIR}${KMODDIR}
.endfor

# For maintainer only.
SVN_MIRROR?=	http://svn.freebsd.org/base
EXPDIR=		${WRKSRC}/src/sys
maintainer-tar-all:
.for r in 8.4 9.1 9.3 10.1
	${MAKE} OSREL=${r} OSVERSION=${r:C/\.//}0000 UNAMER=${r}-RELEASE maintainer-tar
.endfor

maintainer-diff:
.for r in 8 9 10
	${FETCH_CMD} -o ${MASTERDIR}/files-${r}/patch-aa https://github.com/kuriyama/freebsd/compare/freebsd:stable/${r}...6rd-stable-${r}.diff
.endfor
	${FETCH_CMD} -o ${MASTERDIR}/files-9.1/patch-aa https://github.com/kuriyama/freebsd/compare/freebsd:releng/9.1...6rd-releng-9.1.diff

maintainer-tar:
	-${RM} -r ${EXPDIR}
	${MKDIR} ${EXPDIR}
	cd ${EXPDIR} && svn export -r ${SVN_REV} ${SVN_MIRROR}/releng/${OSREL}/sys/net net
	cd ${EXPDIR} && svn export -r ${SVN_REV} ${SVN_MIRROR}/releng/${OSREL}/sys/modules/if_stf modules/if_stf
	${SH} ${MASTERDIR}/files/fixup_mtime.sh ${EXPDIR} ${SVN_REV} ${SVN_MIRROR} ${OSREL}
	cd ${EXPDIR} && ${TAR} cfz ${DISTDIR}/freebsd-stf-${OSREL}-${PORTVERSION}${EXTRACT_SUFX} net modules

maintainer-check:
	@new=`svn log -ql 1 ${SVN_MIRROR}@HEAD releng/${OSREL}/sys/net/if_stf.c | ${GREP} -v ^- | ${SED} -e 's| .*||'`;\
	old="r${SVN_REV}";\
	if [ "$${new}" != "$${old}" ]; then ${ECHO_MSG} "New stf rev: $${new}"; fi

make-distinfo:
	${RM} distinfo.tmp.*
.for r in 8.4 9.1 9.3 10.1
	${MAKE} OSREL=${r} OSVERSION=${r:C/\.//}0000 UNAMER=${r}-RELEASE DISTINFO_FILE=${MASTERDIR}/distinfo.tmp.${r} makesum
.endfor
	${CAT} ${MASTERDIR}/distinfo.tmp.* > ${MASTERDIR}/distinfo
	${RM} distinfo.tmp.*

.include <bsd.port.post.mk>
