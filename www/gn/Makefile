# New ports collection makefile for:    gn
# Version required:     2.17
# Date created:         20 Sep 1994
# Whom:                 adam
#
# $Id: Makefile,v 1.11 1995/10/20 09:14:12 adam Exp $
#

DISTNAME=       gn-2.23
CATEGORIES+=	www net
MASTER_SITES=	ftp://ftp.acns.nwu.edu/pub/gn/

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
	  if [ -s etc/gn_mime.types ]; then \
	    cmp -s etc/gn_mime.types ${WRKSRC}/etc/gn_mime.types || { \
		echo Aborting install due to ${PREFIX}/etc/gn_mime.types; \
		exit 0; \
	    }; \
  	  fi; \
	  if [ -s gnroot/menu ]; then \
	    cmp -s gnroot/menu ${WRKSRC}/gnroot/menu || { \
		echo Aborting install due to ${PREFIX}/gnroot/menu; \
		exit 0; \
	    }; \
	  fi; \
	  tar -cf - -C ${WRKSRC} gnroot libexec bin etc | tar xpf - && \
		(cd gnroot; ${WRKSRC}/bin/mkcache -r); \
	  awk '$$1 == "gopher" { exit 1 }' ${INETD_CONF} || { \
		echo gopher${CONF} >>${INETD_CONF}; \
		kill -HUP \
		`ps ax | awk '$$5 == "inetd" { print $$1 }'`; \
	  }
.endif

.if !defined(DO_PACKAGE)
do-package:
	@${MAKE} ${.MAKEFLAGS} 'PKG_CMD= WRKSRC=${WRKSRC} ${PKG_CMD}' \
		DO_PACKAGE= do-package
.endif

.include <bsd.port.mk>
