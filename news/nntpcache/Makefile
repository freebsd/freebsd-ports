# New ports collection makefile for:	nntpcache
# Version required:	1.0.7.1
# Date created:		6 January 1997
# Whom:			proff@suburbia.net
#
# $Id: Makefile,v 1.7 1997/12/24 01:21:28 alex Exp $
#

DISTNAME=	nntpcache-2.2b4
CATEGORIES=	news
MASTER_SITES=	ftp://nntpcache.org/pub/nntpcache/ \
		ftp://ftp.ntnu.no/pub/unix/news/ \
		ftp://ftp.nethelp.no/pub/unix/news/ \
		ftp://suburbia.net/pub/nntpcache/

BUILD_DEPENDS=	pgp:${PORTSDIR}/security/pgp
MAINTAINER=	nntpcache@nntpcache.org

GNU_CONFIGURE=	TRUE
CONFIGURE_ARGS=	--localstatedir=/var/spool
MAN8=		nntpcached.8

USE_GMAKE=	TRUE

post-configure:
	@sed -e "s:%%PREFIX%%:${PREFIX}:g"  \
		${FILESDIR}/nntpcached.rc > ${WRKSRC}/nntpcached.sh

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/nntpcached.sh ${PREFIX}/etc/rc.d

.include <bsd.port.mk>
