# New ports collection makefile for:	nntpcache
# Version required:	1.0.7.1
# Date created:		6 January 1997
# Whom:			proff@suburbia.net
#
# $Id: Makefile,v 1.6 1997/07/31 06:36:03 asami Exp $
#

DISTNAME=	nntpcache-1.0.7.1
CATEGORIES=	news
MASTER_SITES=	ftp://nntpcache.org/pub/nntpcache/ \
		ftp://ftp.ntnu.no/pub/unix/news/ \
		ftp://ftp.nethelp.no/pub/unix/news/ \
		ftp://suburbia.net/pub/nntpcache/

MAINTAINER=	nntpcache@nntpcache.org

GNU_CONFIGURE=	TRUE
CONFIGURE_ARGS=	--localstatedir=/var/spool
MAN8=		nntpcache.8

post-configure:
	@sed -e "s:%%PREFIX%%:${PREFIX}:g"  \
		${FILESDIR}/nntpcached.rc > ${WRKSRC}/nntpcached.sh

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/nntpcached.sh ${PREFIX}/etc/rc.d
	@-${RM} ${PREFIX}/etc/nntpcache/*.bak

.include <bsd.port.mk>
