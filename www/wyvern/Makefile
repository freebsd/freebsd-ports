# New ports collection makefile for:   Wyvern
# Date created:        3 March 2001
# Whom:                Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	wyvern
PORTVERSION=	2.1.2
CATEGORIES=	www ipv6
MASTER_SITES=	http://www.MysticWALL.COM/download/

MAINTAINER=	kouichi@MysticWALL.COM
COMMENT=	Simple/powerful/lightweight/secure/embed-able HTTP server

USE_BZIP2=		yes
USE_OPENSSL=		yes
USE_GMAKE=		yes
USE_AUTOCONF_VER=	259

NO_MTREE=		yes

PREFIX=		${LOCALBASE}/wyvern
CONFIGURE_ARGS=	--with-ssl=yes \
		--with-ssl-includes="${OPENSSLINC}" \
		--with-ssl-libraries="${OPENSSLLIB}"
MAKE_ARGS=	rcdir="${LOCALBASE}/etc/rc.d"

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400014
CONFIGURE_ARGS+=	--enable-ipv6
.endif

post-extract:
	${MV} ${WRKSRC}/htdocs/index.html ${WRKSRC}/htdocs/index.html-dist

post-install:
	${LN} -sf ${PREFIX}/sbin/wyvern ${LOCALBASE}/sbin/
	if [ ! -f ${PREFIX}/htdocs/index.html ]; then \
		${CP} -p ${PREFIX}/htdocs/index.html-dist ${PREFIX}/htdocs/index.html; \
	fi
	@${CAT} ${PKGMESSAGE}

certificate:
	cd ${PREFIX} && openssl req -config conf/ssl.cnf -new -x509 -nodes \
		-out conf/wyvern.pem -keyout conf/wyvern.pem

.include <bsd.port.post.mk>
