# New ports collection makefile for:    fwtk
# Version required:                     1.3
# Date created:                         15th June 1996
# Whom:                                 gpalmer
#
# $Id: Makefile,v 1.9 1997/05/31 22:41:49 gpalmer Exp $
#

DISTNAME=	fwtk-1.3
CATEGORIES=	security net
DISTFILES=	fwtk-v1.3${EXTRACT_SUFX} fwtk-doc-only${EXTRACT_SUFX}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	obrien@FreeBSD.org

RESTRICTED=	"No form of redistribution is allowed"

WRKSRC=		${WRKDIR}/fwtk
HAS_CONFIGURE=	YES
CONFIGURE_SCRIPT=	fixmake

MAN3=		auth.3
MAN5=		netperm-table.5
MAN8=		authmgr.8 authsrv.8 ftp-gw.8 http-gw.8 login-sh.8 netacl.8 \
		plug-gw.8 rlogin-gw.8 smap.8 smapd.8 tn-gw.8 x-gw.8
DOCS=		sample-report.txt manpages.ps admin_guide.ps user_guide.ps \
		overview.ps presentation.ps
SBIN_BINS=	authdump authload authmgr
LIBEXEC_BINS=	authsrv ftp-gw http-gw netacl plug-gw rlogin-gw smap smapd \
		tn-gw x-gw

do-fetch:
	@if [ ! -f ${DISTDIR}/fwtk-v1.3${EXTRACT_SUFX} ]; then \
	  echo ""; \
	  echo "Please read ftp://ftp.tis.com/pub/firewalls/toolkit/README"; \
	  echo "for details of how to obtain the FTWK source.  Put the files"; \
	  echo "fwtk-v1.3${EXTRACT_SUFX} and fwtk-doc-only${EXTRACT_SUFX} in the directory"; \
	  echo "${DISTDIR} and run make again"; \
	  echo ""; \
	  exit 1;\
	fi

pre-configure:
	@/usr/bin/sed -e s:%%FWTKSRCDIR%%:${WRKSRC}: \
				-e s:%%BSD_PREFIX%%:${PREFIX}: \
				${WRKSRC}/Makefile.config > ${WRKSRC}/Makefile.config.out
	@/bin/mv ${WRKSRC}/Makefile.config.out ${WRKSRC}/Makefile.config

post-install:
	( cd ${PREFIX}/libexec ; strip ${SBIN_BINS} ${LIBEXEC_BINS} )
	( cd ${PREFIX}/libexec ; mv ${SBIN_BINS} ../sbin )
	${MKDIR} ${PREFIX}/share/doc/fwtk
	${INSTALL_MAN} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/fwtk
	( cd ${WRKSRC}/doc/man ; ${INSTALL_MAN} ${MAN3} ${PREFIX}/man/man3 )
	( cd ${WRKSRC}/doc/man ; ${INSTALL_MAN} ${MAN5} ${PREFIX}/man/man5 )
	( cd ${WRKSRC}/doc/man ; ${INSTALL_MAN} ${MAN8} ${PREFIX}/man/man8 )
.if !defined(NOPORTDOCS)
	( cd ${WRKSRC}/doc ; ${INSTALL_MAN} ${DOCS} ${PREFIX}/share/doc/fwtk )
.endif

.include <bsd.port.mk>
