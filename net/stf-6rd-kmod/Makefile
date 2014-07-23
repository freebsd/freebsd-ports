# $FreeBSD$

PORTNAME=	stf
PORTVERSION=	0.${SVN_REV}
CATEGORIES=	net ipv6
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kuriyama
PKGNAMESUFFIX=	-6rd-kmod
DISTNAME=	freebsd-stf-${OSREL}-${PORTVERSION}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	6rd patched stf(4) kernel modules port for 8.4+

ONLY_FOR_ARCHS=	amd64 i386

WRKSRC=		${WRKDIR}
SVN_REV=	267655

USES=		kmod

.include <bsd.port.pre.mk>

.if ${OSREL} == "8.4"
#SVN_REV=	255447
.elif ${OSREL} == "9.1"
#SVN_REV=	255448
.elif ${OSREL} == "9.2"
#SVN_REV=	255444
PATCHDIR=	${MASTERDIR}/files-9.2
.elif ${OSREL} == "9.3"
#SVN_REV=	267655
PATCHDIR=	${MASTERDIR}/files-9.2
#.elif ${OSREL} == "10.0"
##SVN_REV=	258913
#PATCHDIR=	${MASTERDIR}/files-10.0
.else
IGNORE=		not supported $${OSREL} (${OSREL})
.endif

post-extract:
	cd ${WRKSRC} && ${MKDIR} tmp && ${MV} net modules tmp/
	${CP} -Rp ${SRC_BASE}/sys ${WRKSRC}/
	${MKDIR} ${WRKSRC}/share/man
	${CP} -Rp ${SRC_BASE}/share/man/man4 ${WRKSRC}/share/man/
	${CP} -Rp ${WRKSRC}/tmp/* ${WRKSRC}/sys/

pre-patch:
	${REINPLACE_CMD} -e 's|\.Dd July 23, 2011|.Dd April 27, 2001|' ${WRKSRC}/share/man/man4/stf.4

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
maintainer-tar:
.for _osrel in 8.4 9.1 9.2 9.3 10.0
	-${RM} -rf ${EXPDIR}
	${MKDIR} ${EXPDIR}
	cd ${EXPDIR} && svn export -r ${SVN_REV} ${SVN_MIRROR}/releng/${_osrel}/sys/net net
	cd ${EXPDIR} && svn export -r ${SVN_REV} ${SVN_MIRROR}/releng/${_osrel}/sys/modules/if_stf modules/if_stf
	cd ${EXPDIR} && ${TAR} cfz ${DISTDIR}/freebsd-stf-${_osrel}-${PORTVERSION}${EXTRACT_SUFX} net modules
.endfor

maintainer-check:
	@new=`svn log -ql 1 ${SVN_MIRROR}@HEAD releng/${OSREL}/sys/net/if_stf.c | ${GREP} -v ^- | ${SED} -e 's| .*||'`;\
	old="r${SVN_REV}";\
	if [ "$${new}" != "$${old}" ]; then ${ECHO_MSG} "New stf rev: $${new}"; fi

make-distinfo:
	${RM} -f distinfo.tmp.*
.for r in 8.4 9.1 9.2 9.3 10.0
	${MAKE} OSREL=${r} DISTINFO_FILE=${MASTERDIR}/distinfo.tmp.${r} makesum
.endfor
	${CAT} ${MASTERDIR}/distinfo.tmp.* > ${MASTERDIR}/distinfo

.include <bsd.port.post.mk>
