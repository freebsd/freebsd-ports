# New ports collection makefile for:    gn
# Date created:         20 Sep 1994
# Whom:                 adam
#
# $FreeBSD$
#

PORTNAME=	gn
PORTVERSION=	2.24
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.acns.nwu.edu/pub/gn/

MAINTAINER=	adam@veda.is

BUILD_DEPENDS=	${WAISDIR}/bin/waisindex:${PORTSDIR}/net/wais

IS_INTERACTIVE=	yes
NO_PACKAGE=	"Compiled in hostnames"
WAISDIR=	${PORTSDIR}/net/wais/work/freeWAIS-0.5

INETD_CONF=	/etc/inetd.conf
CONF=	'	stream	tcp	nowait	nobody	${PREFIX}/libexec/gn	gn'

pre-build:
	@${LN} -fs ${WAISDIR}/include ${WRKSRC}/waisgn/ir
	@${LN} -fs ${WAISDIR}/bin ${WRKSRC}/waisgn

pre-install:
	@${MKDIR} ${WRKSRC}/etc ${WRKSRC}/libexec ${WRKSRC}/gnroot
	@cd ${WRKSRC}/gnroot; \
		tar -cf - -C ${WRKSRC} docs | tar xpf - && \
			${MV} docs/sample.root.menu menu

post-install:
	@cd ${PREFIX}; \
	  [ -s etc/gn_mime.types ] && \
	  if ! cmp -s etc/gn_mime.types ${WRKSRC}/etc/gn_mime.types; then \
		${ECHO} ${MV} etc/gn_mime.types etc/gn_mime.types.old; \
		${MV} etc/gn_mime.types etc/gn_mime.types.old; \
	  fi; \
	  [ -s gnroot/menu ] && \
	  if ! cmp -s gnroot/menu ${WRKSRC}/gnroot/menu; then \
		${ECHO} ${MV} gnroot/menu gnroot/menu.old; \
		${MV} gnroot/menu gnroot/menu.old; \
	  fi; \
	  tar -cf - -C ${WRKSRC} gnroot libexec bin etc | tar xpf - && \
		(cd gnroot; ${WRKSRC}/bin/mkcache -r); \
	  ${AWK} '$$1 ~ /#*gopher/ && $$6 == "${PREFIX}/libexec/gn" { exit 1 }' \
		${INETD_CONF} || { \ ${ECHO} '#'gopher${CONF} >>${INETD_CONF}
	  }

.include <bsd.port.mk>
