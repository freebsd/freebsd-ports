# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rwhoisd
PORTVERSION=	1.5.9.6
PORTREVISION=	2
CATEGORIES=	net ipv6
MASTER_SITES=	http://projects.arin.net/rwhois/ftp/ \
		http://www.rwhois.net/ftp/ \
		http://www.rwhois.net/ftp/older_releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Internic referral whois server

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	IPV6 LARGEFILE DOCS
OPTIONS_DEFAULT=	IPV6
IPV6_DESC=	Enable IPV6 support
LARGEFILE_DESC=	Enable largefile support (> 2Gb)

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
MAKE_JOBS_UNSAFE=yes

USE_RC_SUBR=	rwhoisd

BINOWN=		bin
BINGRP=		bin

MAN8=		rwhois_indexer.8 rwhoisd.8

PORTDOCS=	INSTALL.html TODO UPGRADE operations_guide.html \
		operations_guide.txt rfc2167.txt security.html security.txt

ETCFILES=	rwhoisd.allow rwhoisd.auth_area rwhoisd.conf rwhoisd.deny \
		rwhoisd.dir rwhoisd.root rwhoisd.x.dir
PLIST_SUB+=	ETCFILES="${ETCFILES}"

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MIPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if ${PORT_OPTIONS:MLARGEFILE}
CONFIGURE_ARGS+=	--enable-largefile
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,userid: rwhoisd,userid: nobody,' \
			  -e 's,pid-file: rwhoisd.pid,pid-file: /var/run/rwhoisd/rwhoisd.pid,' \
		${WRKSRC}/sample.data/rwhoisd.conf
	@${REINPLACE_CMD} -E 's,"(.*\.log)","/var/log/rwhoisd/\1",g' \
		${WRKSRC}/common/conf.h

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/rwhois_indexer.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/doc/rwhoisd.8 ${PREFIX}/man/man8
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
. for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.mk>
