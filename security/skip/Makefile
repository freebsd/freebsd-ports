# New ports collection makefile for:    skip
# Date created:         		26 November 1997
# Whom:                 		Archie L. Cobbs <archie@whistle.com>
#
# $FreeBSD$
#

PORTNAME=		skip
PORTVERSION=		1.0
PORTREVISION=		3
CATEGORIES=		security
# Note: the original source comes from Sun, via this web page:
#    http://skip.incog.com/src-form.html
# The site below is outside of the U.S.
MASTER_SITES=		ftp://ftp.zedz.net/pub/crypto/programs/skip/ \
			ftp://ftp.internat.freebsd.org/pub/FreeBSD/distfiles/
DISTNAME=		skipsrc-1.0
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		archie@freebsd.org
COMMENT=	Stateless IP layer security and encryption from Sun Microsystems

BUILD_DEPENDS=	${X11BASE}/lib/libxview.a:${PORTSDIR}/x11-toolkits/xview \
		${X11BASE}/lib/X11/config/XView.cf:${PORTSDIR}/x11-toolkits/xview
LIB_DEPENDS=	xview.3:${PORTSDIR}/x11-toolkits/xview

# The SKIP code is restricted from export from the United States and Canada.
# See the file doc/00README for legal details.
#NO_PACKAGE=		${RESTRICTED}
#NO_CDROM=		${RESTRICTED}

IS_INTERACTIVE=		yes
NO_WRKSUBDIR=		defined
PATCH_STRIP=		-p1
HAS_CONFIGURE=		defined
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=		freebsd
USE_GMAKE=		defined

MTREE_FILE=		${FILESDIR}/skip.mtree
MAN1=			certreq.1 skiphost.1 skipstat.1 skiptool.1 skipd.1 \
			skipdb.1 skipca.1 skiplocal.1 install_skip_keys.1 \
			skipd_restart.1 skipif.1 skip_conf.1 skiplog.1 \
			print_cert.1
MAN4=			skipd.conf.4 raw_keys.4

# SKIP has a lot of hard coded paths in it. Our patches replace
# them with @@PREFIX@@, which we then replace with ${PREFIX}.
# Also, we remove all the "#pragma ident" lines that generate
# a bazillion warnings from the compiler.
post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -print | ${XARGS} ${RM}
	@cd ${WRKSRC}; \
	FILES=`${FIND} . -type f -print | ${XARGS} ${GREP} -l @@PREFIX@@`; \
	for FILE in $$FILES; do \
	  ${SED} 's!@@PREFIX@@!${PREFIX}!g' < $$FILE > $$FILE.new ; \
	  ${MV} $$FILE.new $$FILE; \
	done; \
	FILES=`${FIND} . -type f -name '*.[cCh]' -print \
	  | ${XARGS} ${GREP} -l '^#pragma ident'`; \
	for FILE in $$FILES; do \
	  ${SED} '/^#pragma ident/d' < $$FILE > $$FILE.new ; \
	  ${MV} $$FILE.new $$FILE; \
	done

# This is for port maintenance, uncomment to regenerate patch set
#diffs:
#	rm -rf patches/patch-*
#	diff -ur --unidirectional-new-file skipsrc-1.0.orig work.new \
#		| split -p ^diff - patches/patch-

.include <bsd.port.mk>
