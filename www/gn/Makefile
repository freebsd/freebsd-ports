# New ports collection makefile for:    gn
# Version required:     2.17
# Date created:         20 Sep 1994
# Whom:                 adam
#
# $Id: Makefile,v 1.4 1994/10/20 12:56:17 adam Exp $
#

DISTNAME=       gn-2.17
MASTER_SITES=	ftp://ftp.acns.nwu.edu/pub/gn/
INETD_CONF=	/etc/inetd.conf
CONF=	'	stream	tcp	nowait	nobody	/usr/local/etc/gn	gn'
DEPENDS=	${PORTSDIR}/net/wais
IS_INTERACTIVE=	yes

pre-build:
	@ln -s ../../../../wais/work/freeWAIS-0.3/ir work/${DISTNAME}/waisgn
	@ln -s ../../../../wais/work/freeWAIS-0.3/bin work/${DISTNAME}/waisgn

pre-install:
	@grep -q '^gopher' ${INETD_CONF} || { \
		echo gopher${CONF} >>${INETD_CONF}; \
		kill -HUP \
		`ps ax | grep inetd | grep -v grep | awk '{ print $$1 }'`; \
	}
	@if [ ! -d /usr/local/gnroot ]; then \
		mkdir -p /usr/local/gnroot; \
		cd /usr/local/gnroot; \
		tar -C ${WRKSRC} -cf - docs | tar xpf -; \
		mv docs/sample.root.menu menu; \
		${WRKSRC}/mkcache/mkcache -r; \
	fi

.include <bsd.port.mk>
