# New ports collection makefile for:    skip
# Version required:     		1.0
# Date created:         		26 November 1997
# Whom:                 		Archie L. Cobbs <archie@whistle.com>
#
# $Id: Makefile,v 1.4 1998/11/17 03:27:52 archie Exp $

DISTNAME=		skip-1.0
CATEGORIES=		security

# Note: the original source comes from Sun, via this web page:
#    http://skip.incog.com/src-form.html
# The site below is outside of the U.S.

MASTER_SITES=		ftp://ftp.asfkasdf.com/pub/replay/crypto/APPS/skip/ \
			ftp://ftp.internat.freebsd.org/pub/FreeBSD/distfiles/

DISTFILES=		skipsrc-1.0.tar.Z
EXTRACT_SUFX=		tar.Z

MAINTAINER=		archie@whistle.com

BUILD_DEPENDS=	${X11BASE}/lib/libxview.a:${PORTSDIR}/x11-toolkits/xview-lib \
		${X11BASE}/lib/X11/config/XView.cf:${PORTSDIR}/x11-toolkits/xview-config
LIB_DEPENDS=	xview.3:${PORTSDIR}/x11-toolkits/xview-lib

# The SKIP code is restricted from export from the United States and Canada.
# See the file doc/00README for legal details.
RESTRICTED=		Contains strong crypto; no export from U.S./Canada
NO_PACKAGE=		${RESTRICTED}
NO_CDROM=		${RESTRICTED}

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
post-patch:
	@find ${WRKSRC} -name '*.orig' -print | xargs rm
	@cd ${WRKSRC}; \
	FILES=`find . -type f -print | xargs grep -l @@PREFIX@@`; \
	for FILE in $$FILES; do \
	  sed 's!@@PREFIX@@!${PREFIX}!g' < $$FILE > $$FILE.new ; \
	  mv $$FILE.new $$FILE; \
	done

.include <bsd.port.mk>
