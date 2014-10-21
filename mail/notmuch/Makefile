# Created by: DarwinSurvivor <darwinsurvivor@gmail.com>
# $FreeBSD$

PORTNAME=	notmuch
PORTVERSION=	0.18.1
CATEGORIES=	mail
MASTER_SITES=	http://notmuchmail.org/releases/

MAINTAINER=	ross@rosstimson.com
COMMENT=	Thread-based email index, search, and tagging application

LICENSE=	GPLv3

BUILD_DEPENDS=	sphinx-build:${PORTSDIR}/textproc/py-sphinx
LIB_DEPENDS=	libgmime-2.6.so:${PORTSDIR}/mail/gmime26 \
		libxapian.so:${PORTSDIR}/databases/xapian-core \
		libtalloc.so:${PORTSDIR}/devel/talloc

HAS_CONFIGURE=	yes
USES=		pkgconfig python:build gmake
CONFIGURE_ARGS=	--prefix=${PREFIX} --mandir=${MANPREFIX}/man
USE_LDCONFIG=	yes

MAKE_ENV+=		PYTHONCMD=${PYTHON_CMD}

.include <bsd.port.mk>
