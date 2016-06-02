# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rwhoisd
PORTVERSION=	1.5.9.6
PORTREVISION=	3
CATEGORIES=	net ipv6
MASTER_SITES=	http://projects.arin.net/rwhois/ftp/ \
		http://www.rwhois.net/ftp/ \
		http://www.rwhois.net/ftp/older_releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Internic referral whois server

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=yes

USE_RC_SUBR=	rwhoisd

BINOWN=		bin
BINGRP=		bin

PORTDOCS=	INSTALL.html TODO UPGRADE operations_guide.html \
		operations_guide.txt rfc2167.txt security.html security.txt

ETCFILES=	rwhoisd.allow rwhoisd.auth_area rwhoisd.conf rwhoisd.deny \
		rwhoisd.dir rwhoisd.root rwhoisd.x.dir
PLIST_SUB+=	ETCFILES="${ETCFILES}"

OPTIONS_DEFINE=	IPV6 DOCS
IPV6_DESC=	Enable IPV6 support
IPV6_CONFIGURE_OFF=	--disable-ipv6

post-patch:
	@${REINPLACE_CMD} -e 's,userid: rwhoisd,userid: nobody,' \
			  -e 's,pid-file: rwhoisd.pid,pid-file: /var/run/rwhoisd/rwhoisd.pid,' \
		${WRKSRC}/sample.data/rwhoisd.conf
	@${REINPLACE_CMD} -E 's,"(.*\.log)","/var/log/rwhoisd/\1",g' \
		${WRKSRC}/common/conf.h

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/*
	${INSTALL_MAN} ${WRKSRC}/doc/rwhois_indexer.8 ${STAGEDIR}${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/doc/rwhoisd.8 ${STAGEDIR}${PREFIX}/man/man8

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
