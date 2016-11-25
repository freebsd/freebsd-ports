# Created by: DarwinSurvivor <darwinsurvivor@gmail.com>
# $FreeBSD$

PORTNAME=	notmuch
PORTVERSION=	0.23.2
CATEGORIES=	mail
MASTER_SITES=	http://notmuchmail.org/releases/

MAINTAINER=	mp39590@gmail.com
COMMENT=	Thread-based email index, search, and tagging application

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING-GPL-3

BUILD_DEPENDS=	c++filt:devel/binutils
LIB_DEPENDS=	libgmime-2.6.so:mail/gmime26 \
		libxapian.so:databases/xapian-core \
		libtalloc.so:devel/talloc

BROKEN_powerpc64=	Does not build

HAS_CONFIGURE=	yes
USES=		gmake pkgconfig python:build
USE_GNOME=	glib20
CONFIGURE_ARGS=	--prefix=${PREFIX} --mandir=${MANPREFIX}/man
USE_LDCONFIG=	yes

MAKE_ENV+=		PYTHONCMD=${PYTHON_CMD}

OPTIONS_DEFINE=	BASH DOXYGEN EMACS MANPAGES MUTT RUBY ZSH
EMACS_DESC=	Install EMACS lisp files (requires emacs)
MUTT_DESC=	Install notmuch-mutt script
OPTIONS_SUB=	yes

BASH_BUILD_DEPENDS=	bash-completion>=1.90:shells/bash-completion
BASH_RUN_DEPENDS=	${BASH_BUILD_DEPENDS}
BASH_CONFIGURE_WITH=	bash-completion
DOXYGEN_CONFIGURE_WITH=	api-docs
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
EMACS_CONFIGURE_WITH=	emacs
EMACS_CONFIGURE_ON=	--emacslispdir=${PREFIX}/${EMACS_SITE_LISPDIR} \
			--emacsetcdir=${PREFIX}/${EMACS_SITE_LISPDIR}
EMACS_USE=	EMACS=yes
MANPAGES_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx
MUTT_RUN_DEPENDS=	p5-Mail-Tools>0:mail/p5-Mail-Tools \
			p5-Mail-Box>0:mail/p5-Mail-Box \
			p5-String-ShellQuote>0:textproc/p5-String-ShellQuote
MUTT_USE=	PERL=yes
RUBY_USE=	RUBY=yes
ZSH_CONFIGURE_WITH=	zsh-completion

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000000
CONFIGURE_ENV=	zlib_cflags="" zlib_ldflags="-lz" PKG_CONFIG_PATH=""
.endif

do-build-MUTT-on:
	${MAKE_CMD} -C ${WRKSRC}/contrib/notmuch-mutt all
	${GZIP_CMD} ${WRKSRC}/contrib/notmuch-mutt/notmuch-mutt.1

do-install-MUTT-on:
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/notmuch-mutt/notmuch-mutt ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/contrib/notmuch-mutt/notmuch-mutt.1.gz ${STAGEDIR}${MANPREFIX}/man/man1

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/notmuch
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libnotmuch.so.4.4.0

.include <bsd.port.post.mk>
