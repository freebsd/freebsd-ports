# New ports collection makefile for:    gn
# Version required:     2.24
# Date created:         20 Sep 1994
# Whom:                 adam
#
# $Id: Makefile,v 1.18 1996/12/07 11:26:57 max Exp $
#

DISTNAME=       gn-2.24
CATEGORIES=	www net
MASTER_SITES=	ftp://ftp.acns.nwu.edu/pub/gn/

MAINTAINER=	adam@veda.is

BUILD_DEPENDS=	${WAISDIR}/bin/waisindex:${PORTSDIR}/net/wais

IS_INTERACTIVE=	yes
NO_PACKAGE=	"Compiled in hostnames"
WAISDIR=	${PORTSDIR}/net/wais/work/freeWAIS-0.5

INETD_CONF=	/etc/inetd.conf
CONF=	'	stream	tcp	nowait	nobody	/usr/local/libexec/gn	gn'

pre-build:
	@ln -fs ${WAISDIR}/include ${WRKSRC}/waisgn/ir
	@ln -fs ${WAISDIR}/bin ${WRKSRC}/waisgn

pre-install:
	@mkdir -p ${WRKSRC}/etc ${WRKSRC}/libexec ${WRKSRC}/gnroot
	@cd ${WRKSRC}/gnroot; \
		tar -cf - -C ${WRKSRC} docs | tar xpf - && \
			mv docs/sample.root.menu menu

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
	  awk '$$1 ~ /#*gopher/ && $$6 == "/usr/local/libexec/gn" { exit 1 }' \
		${INETD_CONF} || { \ echo '#'gopher${CONF} >>${INETD_CONF}
	  }

.include <bsd.port.mk>
