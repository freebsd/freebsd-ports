PORTNAME=	keyd
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.0
CATEGORIES=	sysutils

MAINTAINER=	chalpin@cs.wisc.edu
COMMENT=	Key remapping daemon for evdev
WWW=		https://github.com/rvaiya/keyd

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto
LIB_DEPENDS=	libinotify.so:devel/libinotify

USES=		gmake python:env shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	rvaiya
USE_RC_SUBR=	${PORTNAME}
SHEBANG_FILES=	scripts/*
MAKE_ARGS=	VERSION="${DISTVERSIONFULL}" COMMIT=""
USERS=		${PORTNAME}
GROUPS=		${PORTNAME}
PLIST_DIRS=	${ETCDIR}
PLIST_FILES=	bin/${PORTNAME} \
		bin/${PORTNAME}-application-mapper
PORTDATA=	*
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES MANPAGES
OPTIONS_DEFAULT=MANPAGES

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_ALL_TARGET=	all man
MANPAGES_PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz \
			share/man/man1/${PORTNAME}-application-mapper.1.gz \

post-patch:
	@${REINPLACE_CMD} -e 's,/etc,$$(PREFIX)&,' \
		-e 's,/usr/local,${LOCALBASE},' \
		-e 's,${DOCSDIR_REL}/examples,${EXAMPLESDIR_REL},' \
		-e 's/ -O3//' \
		-e 's,v$$(VERSION)\\ \\($$(COMMIT)\\),$$(VERSION),' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's,/usr,${PREFIX},' \
		-e 's,/etc,${PREFIX}&,' \
		${WRKSRC}/docs/*.scdoc \
		${WRKSRC}/examples/*.conf
# https://lists.freebsd.org/pipermail/freebsd-x11/2019-March/023097.html
	@${REINPLACE_CMD} -e 's,__FreeBSD,&_disabled,' \
		${WRKSRC}/src/keyd.h \
		${WRKSRC}/src/vkbd/uinput.c

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
