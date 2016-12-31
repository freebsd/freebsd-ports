# $FreeBSD$

PORTNAME=	bnxt-kmod
PORTVERSION=	309078
CATEGORIES=	net
MASTER_SITES=	LOCAL/shurd

MAINTAINER=	shurd@FreeBSD.org
COMMENT=	Driver for Broadcom NetXtreme-C/NetXtreme-E devices

LICENSE=	BSD2CLAUSE

USES=		kmod
BUILD_WRKSRC=	${WRKSRC}/sys/modules/bnxt

PLIST_FILES=	${KMODDIR}/if_bnxt.ko \
		man/man4/bnxt.4.gz \
		man/man4/if_bnxt.4.gz

create-tarball:
	${MKDIR} ${WRKDIR}
	svnlite checkout -r ${PORTVERSION} --depth empty https://svn.freebsd.org/base/head ${WRKSRC}
	svnlite update -r ${PORTVERSION} --set-depth empty ${WRKSRC}/sys
	svnlite update -r ${PORTVERSION} --set-depth empty ${WRKSRC}/sys/dev
	svnlite update -r ${PORTVERSION} --set-depth infinity ${WRKSRC}/sys/dev/bnxt
	svnlite update -r ${PORTVERSION} --set-depth empty ${WRKSRC}/sys/modules
	svnlite update -r ${PORTVERSION} --set-depth infinity ${WRKSRC}/sys/modules/bnxt
	svnlite update -r ${PORTVERSION} --set-depth empty ${WRKSRC}/share
	svnlite update -r ${PORTVERSION} --set-depth empty ${WRKSRC}/share/man
	svnlite update -r ${PORTVERSION} --set-depth empty ${WRKSRC}/share/man/man4
	svnlite update -r ${PORTVERSION} ${WRKSRC}/share/man/man4/bnxt.4
	tar czf ${DISTNAME}${EXTRACT_SUFX} -C ${WRKDIR} --exclude=.svn ${DISTNAME}
	scp ${DISTNAME}${EXTRACT_SUFX} freefall:public_distfiles/

post-patch:
	@${REINPLACE_CMD} -e 's|%%PORTVERSION%%|${PORTVERSION}|' ${WRKSRC}/sys/dev/bnxt/if_bnxt.c

do-install:
	${INSTALL_KLD} ${WRKSRC}/sys/modules/bnxt/if_bnxt.ko ${STAGEDIR}${KMODDIR}/if_bnxt.ko
	${INSTALL_MAN} ${WRKSRC}/share/man/man4/bnxt.4 ${STAGEDIR}${MAN4PREFIX}/man/man4/
	${LN} -f ${STAGEDIR}${MAN4PREFIX}/man/man4/bnxt.4 ${STAGEDIR}${MAN4PREFIX}/man/man4/if_bnxt.4

.include <bsd.port.pre.mk>

SUPPORTED=	no
.if ${OSVERSION} >= 1100122
.if ${OSVERSION} < 1100500
SUPPORTED=	yes
.endif
.endif
.if ${OSVERSION} >= 1100501
.if ${OSVERSION} < 1101000
SUPPORTED=	yes
.endif
.endif
.if ${OSVERSION} >= 1200002
.if ${OSVERSION} <= 1200014
SUPPORTED=	yes
.endif
.endif
.if ${SUPPORTED} == no
IGNORE=		not supported on this version of FreeBSD
.endif

.include <bsd.port.post.mk>
