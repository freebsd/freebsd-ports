# Created by: DarwinSurvivor <darwinsurvivor@gmail.com>
# $FreeBSD$

PORTNAME=	notmuch
PORTVERSION=	0.17
CATEGORIES=	mail
MASTER_SITES=	http://notmuchmail.org/releases/

MAINTAINER=	ross@rosstimson.com
COMMENT=	Thread-based email index, search, and tagging application

LICENSE=	GPLv3

LIB_DEPENDS=	libgmime-2.6.so:${PORTSDIR}/mail/gmime26 \
		libxapian.so:${PORTSDIR}/databases/xapian-core \
		libtalloc.so:${PORTSDIR}/devel/talloc

HAS_CONFIGURE=	yes
USES=		pkgconfig gmake
CONFIGURE_ARGS=	--prefix=${PREFIX} --mandir=${MANPREFIX}/man
USE_LDCONFIG=	yes

.include <bsd.port.mk>
