# New ports collection makefile for:    fwtk
# Version required:                     1.3
# Date created:                         15th June 1996
# Whom:                                 gpalmer
#
# $Id$
#

DISTNAME=       fwtk-1.3
CATEGORIES+=    security net
MASTER_SITES=   ftp://ftp.tis.com/pub/firewalls/toolkit
DISTFILES=	fwtk-v1.3.tar.Z fwtk-doc-only.tar.Z

MAINTAINER=     gpalmer@FreeBSD.ORG

WRKSRC=         ${WRKDIR}/fwtk
HAS_CONFIGURE=	YES
CONFIGURE_SCRIPT=	fixmake

RESTRICTED=	"No form of redistribution is allowed"

INSTMAN=	/usr/bin/install -c -o ${BINOWN} -g ${BINGRP}

MAN3=		auth.3
MAN5=		netperm-table.5
MAN8= 		authmgr.8 authsrv.8 ftp-gw.8 http-gw.8 login-sh.8 netacl.8 \
		plug-gw.8 rlogin-gw.8 smap.8 smapd.8 tn-gw.8 x-gw.8
DOCS=		sample-report.txt manpages.ps admin_guide.ps user_guide.ps \
		overview.ps presentation.ps
SBIN_BINS=	authdump authload authmgr
LIBEXEC_BINS=	authsrv ftp-gw http-gw netacl plug-gw rlogin-gw smap smapd \
		tn-gw x-gw

post-install:
	( cd ${PREFIX}/libexec ; strip ${SBIN_BINS} ${LIBEXEC_BINS} )
	( cd ${PREFIX}/libexec ; mv ${SBIN_BINS} ../sbin )
	mkdir -p ${PREFIX}/share/doc/fwtk
	${INSTMAN} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/fwtk
	( cd ${WRKSRC}/doc/man ; ${INSTMAN} ${MAN3} ${PREFIX}/man/man3 )
	( cd ${WRKSRC}/doc/man ; ${INSTMAN} ${MAN5} ${PREFIX}/man/man5 )
	( cd ${WRKSRC}/doc/man ; ${INSTMAN} ${MAN8} ${PREFIX}/man/man8 )
.if !defined(NOMANCOMPRESS)
	( cd ${PREFIX}/man/man3; gzip -9nfv ${MAN3} )
	( cd ${PREFIX}/man/man5; gzip -9nfv ${MAN5} )
	( cd ${PREFIX}/man/man8; gzip -9nfv ${MAN8} )
.endif
.if !defined(NOPORTDOCS)
	( cd ${WRKSRC}/doc ; cp ${DOCS} ${PREFIX}/share/doc/fwtk
.endif

.include <bsd.port.mk>
