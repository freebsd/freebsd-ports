# Created by: ijliao
# $FreeBSD$

PORTNAME=	pen
PORTVERSION=	0.18.0
CATEGORIES=	net
MASTER_SITES=	ftp://siag.nu/pub/pen/ \
		http://siag.nu/pub/pen/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A load balancer for simple TCP based protocols

GNU_CONFIGURE=		yes
USE_OPENSSL=		yes
USE_RC_SUBR=		pen
CONFIGURE_ARGS=		--with-daemon --with-docdir=${DOCSDIR} \
			--with-ssl=${OPENSSLBASE}

PORTDOCS=		penstats HOWTO AUTHORS README ChangeLog COPYING
PLIST_FILES=		bin/mergelogs bin/pen bin/penctl bin/penlog \
			bin/penlogd man/man1/mergelogs.1.gz \
			man/man1/pen.1.gz man/man1/penctl.1.gz \
			man/man1/penlog.1.gz man/man1/penlogd.1.gz

.if defined(WITH_FDSETSIZE)
CONFIGURE_ARGS+=	--with-fd_setsize=${WITH_FDSETSIZE}
.endif

.if defined(WITH_POLL)
CONFIGURE_ARGS+=	--with-poll
.else
CONFIGURE_ARGS+=	--with-kqueue
.endif

.if defined(NOPORTDOCS)
MAKE_ARGS+=	-DNOPORTDOCS
.endif

.include <bsd.port.mk>
