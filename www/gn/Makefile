# New ports collection makefile for:    gn
# Version required:     2.24
# Date created:         20 Sep 1994
# Whom:                 adam
#
# $Id: Makefile,v 1.13 1996/02/09 09:42:00 adam Exp $
#

DISTNAME=       gn-2.24
CATEGORIES+=	www net
MASTER_SITES=	ftp://ftp.acns.nwu.edu/pub/gn/

MAINTAINER=	adam@veda.is

WAISDIR=	${PORTSDIR}/net/wais/work/freeWAIS-0.3
BUILD_DEPENDS=	${WAISDIR}/bin/waisindex:${PORTSDIR}/net/wais

IS_INTERACTIVE=	yes
# This quaint mechanism is for forcing package creation from a staging area.
.if !defined(YES_PACKAGE)
YES_INSTALL=
NO_PACKAGE=	# compiled in hostnames
.endif

INETD_CONF=	/etc/inetd.conf
CONF=	'	stream	tcp	nowait	nobody	/usr/local/libexec/gn	gn'

pre-build:
	@ln -fs ${WAISDIR}/ir ${WRKSRC}/waisgn
	@ln -fs ${WAISDIR}/bin ${WRKSRC}/waisgn

pre-install:
	@mkdir -p ${WRKSRC}/etc ${WRKSRC}/libexec ${WRKSRC}/gnroot
	@cd ${WRKSRC}/gnroot; \
		tar -cf - -C ${WRKSRC} docs | tar xpf - && \
			mv docs/sample.root.menu menu

.if defined(YES_INSTALL)
post-install:
	@cd ${PREFIX}; \
	  [ -s etc/gn_mime.types ] && \
	  if ! cmp -s etc/gn_mime.types ${WRKSRC}/etc/gn_mime.types; then \
		echo mv etc/gn_mime.types etc/gn_mime.types.old; \
		mv etc/gn_mime.types etc/gn_mime.types.old; \
  	  fi; \
	  [ -s gnroot/menu ] && \
	  if ! cmp -s gnroot/menu ${WRKSRC}/gnroot/menu; then \
		echo mv gnroot/menu gnroot/menu.old; \
		mv gnroot/menu gnroot/menu.old; \
	  fi; \
	  tar -cf - -C ${WRKSRC} gnroot libexec bin etc | tar xpf - && \
		(cd gnroot; ${WRKSRC}/bin/mkcache -r); \
	  awk '$$1 == "#gopher" { exit 1 }' ${INETD_CONF} || { \
		echo '#'gopher${CONF} >>${INETD_CONF}
	  }
.endif

.if !defined(DO_PACKAGE)
do-package:
	@${MAKE} ${.MAKEFLAGS} 'PKG_CMD= WRKSRC=${WRKSRC} ${PKG_CMD}' \
		DO_PACKAGE= do-package
.endif

.include <bsd.port.mk>
