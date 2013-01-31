# Created by: DarwinSurvivor <darwinsurvivor@gmail.com>
# $FreeBSD$

PORTNAME=	notmuch
PORTVERSION=	0.15.1
CATEGORIES=	mail
MASTER_SITES=	http://notmuchmail.org/releases/

MAINTAINER=	ross@rosstimson.com
COMMENT=	Thread-based email index, search, and tagging application

LICENSE=	GPLv3

LIB_DEPENDS=	gmime-2.4:${PORTSDIR}/mail/gmime24 \
		xapian:${PORTSDIR}/databases/xapian-core \
		talloc:${PORTSDIR}/devel/talloc

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --mandir=${MANPREFIX}/man
USE_GMAKE=	yes
USE_LDCONFIG=	yes

MAN1=		notmuch.1 notmuch-config.1 \
		notmuch-count.1 notmuch-dump.1 \
		notmuch-new.1 notmuch-reply.1 \
		notmuch-restore.1 notmuch-search.1 \
		notmuch-setup.1 notmuch-show.1 \
		notmuch-tag.1
MAN5=		notmuch-hooks.5
MAN7=		notmuch-search-terms.7
MANCOMPRESSED=	yes

.include <bsd.port.mk>
