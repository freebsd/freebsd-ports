# Created by: DarwinSurvivor <darwinsurvivor@gmail.com>
# $FreeBSD$

PORTNAME=	notmuch
PORTVERSION=	0.21
CATEGORIES=	mail
MASTER_SITES=	http://notmuchmail.org/releases/

MAINTAINER=	mp39590@gmail.com
COMMENT=	Thread-based email index, search, and tagging application

LICENSE=	GPLv3

BROKEN_powerpc64=	Does not build

BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx \
		c++filt:devel/binutils
LIB_DEPENDS=	libgmime-2.6.so:mail/gmime26 \
		libxapian.so:databases/xapian-core \
		libtalloc.so:devel/talloc

OPTIONS_DEFINE=	BASH EMACS ZSH
BASH_DESC=	Install bash completion (requires shells/bash-completion)
EMACS_DESC=	Install EMACS lisp files (requires emacs)
ZSH_DESC=	Install zsh completion
OPTIONS_SUB=	yes

BASH_BUILD_DEPENDS=	bash-completion>=1.90:shells/bash-completion
BASH_RUN_DEPENDS=	${BASH_BUILD_DEPENDS}
BASH_CONFIGURE_OFF=	--without-bash-completion
EMACS_CONFIGURE_OFF=	--without-emacs
EMACS_CONFIGURE_ON=	--emacslispdir=${PREFIX}/${EMACS_SITE_LISPDIR} \
			--emacsetcdir=${PREFIX}/${EMACS_SITE_LISPDIR}
EMACS_USE=		EMACS=yes
ZSH_CONFIGURE_OFF=	--without-zsh-completion

HAS_CONFIGURE=	yes
USES=		gmake pkgconfig python:build
CONFIGURE_ARGS=	--prefix=${PREFIX} --mandir=${MANPREFIX}/man
USE_LDCONFIG=	yes

MAKE_ENV+=		PYTHONCMD=${PYTHON_CMD}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/notmuch
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libnotmuch.so.4.3.0

.include <bsd.port.mk>
