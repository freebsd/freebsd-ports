# Created by: DarwinSurvivor <darwinsurvivor@gmail.com>

PORTNAME=	notmuch
DISTVERSION=	0.35
PORTREVISION?=	0
CATEGORIES?=	mail
MASTER_SITES=	https://notmuchmail.org/releases/

MAINTAINER=	jrm@FreeBSD.org
COMMENT?=	Thread-based email index, search and tagging application

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/${WRKSRC_SUBDIR:C/[^\/]+/../g}/COPYING-GPL-3

.ifndef MASTERDIR
LIB_DEPENDS=	libgmime-3.0.so:mail/gmime30 \
		libsexp.so:devel/sfsexp \
		libtalloc.so:devel/talloc \
		libxapian.so:databases/xapian-core
TEST_DEPENDS=	${LOCALBASE}/bin/gdb:devel/gdb \
		bash:shells/bash \
		dtach:misc/dtach \
		emacs:editors/emacs@nox \
		gbase64:sysutils/coreutils \
		gdate:sysutils/coreutils \
		gpg:security/gnupg \
		gsed:textproc/gsed \
		gsha256sum:sysutils/coreutils \
		gwc:sysutils/coreutils

USES=		compiler:c++11-lang gmake gnome pkgconfig \
		python:3.5+,build,test
USE_GNOME=	glib20
USE_LDCONFIG=	yes
.endif

USES+=		tar:xz

.ifndef MASTERDIR
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--infodir=${PREFIX}/${INFO_PATH} \
		--mandir=${MANPREFIX}/man \
		--prefix=${PREFIX} \
		--with-bash-completion \
		--with-retry-lock \
		--with-zsh-completion \
		--without-emacs
CONFIGURE_ENV+=	PYTHON=${PYTHON_CMD}
TEST_ENV+=	NOTMUCH_SKIP_TESTS="basic.12 count.14 insert.2[89] insert.3[0-9] message-property.6 regexp-query.21" \
		TEST_CFLAGS="-g -O0 -I${LOCALBASE}/include -L${LOCALBASE}/lib" \
		TEST_GDB=${LOCALBASE}/bin/gdb \
		V=1
TEST_TARGET=	test
.endif

PKGDIR=		${.CURDIR}
.ifndef MASTERDIR
PORTSCOUT=	limit:^[0-9\.]*$$
.endif

PATCH_WRKSRC=	${WRKSRC}/${WRKSRC_SUBDIR:C/[^\/]+/../g}

.ifndef MASTERDIR
OPTIONS_DEFINE=		DOXYGEN MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

DOXYGEN_BUILD_DEPENDS=		doxygen:devel/doxygen
DOXYGEN_CONFIGURE_WITH=		api-docs
MANPAGES_BUILD_DEPENDS=		sphinx-build:textproc/py-sphinx
MANPAGES_CONFIGURE_WITH=	docs

# Avoid conflict with C++20 <version> by ignoring <...> under WRKSRC
post-patch:
	@${REINPLACE_CMD} -i .c++20 's/-I$$(srcdir)/-iquote$$(srcdir)/' \
		${WRKSRC}/*/Makefile.local

# Install bash completions without incurring a dependency on
# shells/bash-completion.
post-configure:
	${REINPLACE_CMD} \
		-e '/^BASH_ABSOLUTE[[:blank:]]*=/s|=.*|=${LOCALBASE}/bin/bash|' \
		-e '/^HAVE_BASH[[:blank:]]*=/s/=.*/=1/' \
		-e '/^WITH_BASH[[:blank:]]*=/s/=.*/=1/' \
		${WRKSRC}/Makefile.config

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/notmuch
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libnotmuch.so.?*.?*.?*

# Keep poudriere-testport(8) happy.
post-install-MANPAGES-on:
	@${RM} ${STAGEDIR}${MANPREFIX}/man/man1/notmuch-emacs-mua.1.gz
.endif

.include <bsd.port.mk>
