# ex:ts=8
# Ports collection makefile for:  fwtk
# Date created:			  15th June 1996
# Whom:				  gpalmer
#
# $FreeBSD$
#

PORTNAME=	fwtk
PORTVERSION=	2.1
CATEGORIES=	security
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	.tar.Z
DISTFILES=	fwtk2.1${EXTRACT_SUFX} fwtk-doc-only${EXTRACT_SUFX}
DIST_SUBDIR=	fwtk

.if defined(WITH_JUMBO_PATCH)
PATCHFILES=	trg-jumbo-20001114.diff
PATCH_SITES=	http://www.fwtk.org/fwtk/patches/
PATCH_DIST_STRIP=	-p1
.endif

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A toolkit used for building firewalls based on proxy services

RESTRICTED=	"No form of redistribution is allowed"

WRKSRC=		${WRKDIR}/fwtk
HAS_CONFIGURE=	YES
CONFIGURE_SCRIPT=	fixmake

MAN3=		auth.3
MAN5=		netperm-table.5
MAN8=		authmgr.8 authsrv.8 ftp-gw.8 http-gw.8 login-sh.8 netacl.8 \
		plug-gw.8 rlogin-gw.8 smap.8 smapd.8 tn-gw.8
DOCS=		sample-report.txt manpages.ps admin_guide.ps user_guide.ps \
		overview.ps presentation.ps
SBIN_BINS=	authdump authload authmgr
LIBEXEC_BINS=	authsrv ftp-gw http-gw netacl plug-gw rlogin-gw smap smapd \
		tn-gw

.if !defined(WITHOUT_X11)
LIBEXEC_BINS+=	x-gw
MAN8+=		x-gw.8
.endif

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DIST_SUBDIR}/fwtk2.1${EXTRACT_SUFX}) \
	&& !exists(${DISTDIR}/${DIST_SUBDIR}fwtk-doc-only${EXTRACT_SUFX})
IGNORE='Please read ftp://ftp.tislabs.com/pub/firewalls/toolkit/dist/README for details of how to obtain the FTWK source.  Put the files fwtk2.1${EXTRACT_SUFX} and fwtk-doc-only${EXTRACT_SUFX} into the directory ${DISTDIR}/${DIST_SUBDIR} and run make again'
.endif

pre-patch:
.if !defined(WITH_JUMBO_PATCH)
	@${ECHO} "*****************************************************************************"
	@${ECHO} "****  To enable the \"Jumbo\" patch kit, run 'make -DWITH_JUMBO_PATCH'"
	@${ECHO} "****  For information about patches, read http://www.fwtk.org/fwtk/patches/"
	@${ECHO} "*****************************************************************************"
.endif

pre-configure:
	@${MV} ${WRKSRC}/Makefile.config ${WRKSRC}/Makefile.config.in
	@${SED} -e s:%%FWTKSRCDIR%%:${WRKSRC}: \
		-e s:%%BSD_PREFIX%%:${PREFIX}: \
		${WRKSRC}/Makefile.config.in > ${WRKSRC}/Makefile.config
	@${MV} ${WRKSRC}/firewall.h ${WRKSRC}/firewall.h.in
	@${SED} -e s:%%FWTKSRCDIR%%:${WRKSRC}: \
		-e s:%%BSD_PREFIX%%:${PREFIX}: \
		${WRKSRC}/firewall.h.in > ${WRKSRC}/firewall.h

post-install:
	cd ${PREFIX}/libexec ; strip ${SBIN_BINS} ${LIBEXEC_BINS}
	cd ${PREFIX}/libexec ; ${MV} ${SBIN_BINS} mqueue ../sbin
	${INSTALL_DATA} ${WRKSRC}/config/netperm-table \
		${PREFIX}/etc/netperm-table.sample
	if [ ! -f ${PREFIX}/etc/netperm-table ]; then \
		${INSTALL_DATA} ${WRKSRC}/config/netperm-table \
		${PREFIX}/etc/netperm-table;\
	fi
.for file in ${LIBEXEC_BINS}
	@${RM} -f ${PREFIX}/libexec/${file}.old
.endfor
.for man in ${MAN3}
	@${INSTALL_MAN} ${WRKSRC}/doc/man/${man} ${PREFIX}/man/man3
.endfor
.for man in ${MAN5}
	@${INSTALL_MAN} ${WRKSRC}/doc/man/${man} ${PREFIX}/man/man5
.endfor
.for man in ${MAN8}
	@${INSTALL_MAN} ${WRKSRC}/doc/man/${man} ${PREFIX}/man/man8
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}
.for files in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${files} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
