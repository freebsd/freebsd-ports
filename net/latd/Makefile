# Created by: Tillman Hodgson <tillman@seekingfire.com>
# $FreeBSD$

PORTNAME=	latd
PORTVERSION=	1.31
CATEGORIES=	net
MASTER_SITES=	SF/linux-decnet/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Linux-DECnet project LAT protocol suite

LICENSE=	GPLv2

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/llogin etc/latd.conf.sample \
		man/man1/llogin.1.gz man/man5/latd.conf.5.gz \
		man/man8/latd.8.gz man/man8/latcp.8.gz man/man8/moprc.8.gz \
		sbin/latcp sbin/latd sbin/moprc

post-extract:
	@${CHMOD} ${BINMODE} ${WRKSRC}/install-sh

post-patch:
	@${FIND} ${WRKSRC} -name "*.cc" | ${XARGS} ${REINPLACE_CMD} -e \
		'/<utmp.h>/s|^|// | ; \
		 s| \(setiosflags\)| std::\1| ; \
		 s| \(resetiosflags\)| std::\1|'

.include <bsd.port.mk>
