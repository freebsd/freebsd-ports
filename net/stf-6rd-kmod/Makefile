# $FreeBSD$

PORTNAME=	stf
PORTVERSION=	0.${SVN_REV}
CATEGORIES=	net ipv6
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kuriyama
PKGNAMESUFFIX=	-6rd-kmod
DISTNAME=	freebsd-stf-${OSREL}-${PORTVERSION}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	6rd patched stf(4) kernel modules port for 8.3+

ONLY_FOR_ARCHS=	amd64 i386

WRKSRC=		${WRKDIR}
SVN_REV=	239080	# 8.1=r209773, 8.2=r216741, 8.3=r232314

NO_STAGE=	yes

USES=		kmod
.include <bsd.port.pre.mk>

.if ${OSREL} != "8.1" && ${OSREL} != "8.2" && ${OSREL} != "8.3" && ${OSREL} != "8.4" && ${OSREL} != "9.1"
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
	${INSTALL_KLD} ${WRKSRC}/sys/modules/if_stf/${f}.ko ${KMODDIR}
	${INSTALL_KLD} ${WRKSRC}/sys/modules/if_stf/${f}.ko.symbols ${KMODDIR}
.endfor

post-install:
	${CAT} ${PKGMESSAGE}

# For maintainer only.
SVN_MIRROR?=	http://svn.freebsd.org/base
EXPDIR=		${WRKSRC}/src/sys
maintainer-tar:
	${MKDIR} ${EXPDIR}
	cd ${EXPDIR} && svn export -r ${SVN_REV} ${SVN_MIRROR}/releng/${OSREL}/sys/net net
	cd ${EXPDIR} && svn export -r ${SVN_REV} ${SVN_MIRROR}/releng/${OSREL}/sys/modules/if_stf modules/if_stf
	cd ${EXPDIR} && ${TAR} cfvz ${DISTDIR}/${DISTFILES} net modules

maintainer-check:
	@new=`svn log -ql 1 ${SVN_MIRROR}@HEAD releng/${OSREL}/sys/net/if_stf.c | ${GREP} -v ^- | ${SED} -e 's| .*||'`;\
	old="r${SVN_REV}";\
	if [ "$${new}" != "$${old}" ]; then ${ECHO_MSG} "New stf rev: $${new}"; fi

make-distinfo:
	${RM} -f distinfo.tmp.*
.for r in 8.1 8.2 8.3 8.4 9.1
	${MAKE} OSREL=${r} DISTINFO_FILE=${MASTERDIR}/distinfo.tmp.${r} makesum
.endfor
	${CAT} ${MASTERDIR}/distinfo.tmp.* > ${MASTERDIR}/distinfo

.include <bsd.port.post.mk>
