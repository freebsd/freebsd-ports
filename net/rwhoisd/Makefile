# New ports collection makefile for:	rwhoisd
# Date created:				May 9th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rwhoisd
PORTVERSION=	1.5.9.6
PORTREVISION=	1
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.rwhois.net/ftp/ \
		http://www.rwhois.net/ftp/older_releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Internic referral whois server

OPTIONS=	IPV6 "Enable IPV6 support" On \
		LARGEFILE "Enable largefile support (> 2Gb)" Off

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

USE_RC_SUBR=	rwhoisd

BINOWN=		bin
BINGRP=		bin

MAN8=		rwhois_indexer.8 rwhoisd.8

PORTDOCS=	INSTALL.html TODO UPGRADE operations_guide.html \
		operations_guide.txt rfc2167.txt security.html security.txt

.include <bsd.port.pre.mk>

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if defined(WITH_LARGEFILE)
CONFIGURE_ARGS+=	--enable-largefile
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,rwhoisd/samples,rwhoisd,' \
		${WRKSRC}/sample.data/Makefile.in
	@${REINPLACE_CMD} -e 's,userid: rwhoisd,userid: nobody,' \
			  -e 's,pid-file: rwhoisd.pid,pid-file: /var/run/rwhoisd/rwhoisd.pid,' \
		${WRKSRC}/sample.data/rwhoisd.conf
	@${REINPLACE_CMD} -E 's,"(.*\.log)","/var/log/rwhoisd/\1",g' \
		${WRKSRC}/common/conf.h

post-install:
	@${MKDIR} /var/log/rwhoisd /var/run/rwhoisd
	@${CHOWN} -R nobody /var/log/rwhoisd /var/run/rwhoisd
	${INSTALL_MAN} ${WRKSRC}/doc/rwhois_indexer.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/doc/rwhoisd.8 ${PREFIX}/man/man8
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
. for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.post.mk>
