CATEGORIES=	mail ruby
PKGNAMEPREFIX=	ruby-

COMMENT=	Ruby interface for the Notmuch email search and tagging library

LICENSE=	GPLv3

LIB_DEPENDS=	libnotmuch.so:mail/notmuch \
		libtalloc.so:devel/talloc

USES=		gmake pkgconfig python:build,test ruby

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-emacs
CONFIGURE_ENV+=	PYTHON=${PYTHON_CMD} \
		RUBY=${RUBY_CMD}

ALL_TARGET=	ruby-bindings
MASTERDIR=	${.CURDIR}/../notmuch

do-install:
	${MAKE_CMD} DESTDIR=${STAGEDIR} -C ${WRKSRC}/bindings/ruby install
	${STRIP_CMD} ${STAGEDIR}${RUBY_VENDORARCHLIBDIR}/notmuch.so

.include "${MASTERDIR}/Makefile"
