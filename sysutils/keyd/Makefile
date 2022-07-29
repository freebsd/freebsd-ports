PORTNAME=	keyd
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.2
CATEGORIES=	sysutils

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Key remapping daemon for evdev

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto
LIB_DEPENDS=	libinotify.so:devel/libinotify

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake python:env shebangfix
USE_GITHUB=	yes
USE_RC_SUBR=	${PORTNAME}
GH_ACCOUNT=	rvaiya
SHEBANG_FILES=	scripts/*
MAKE_ARGS=	DESTDIR="${DESTDIR}" PREFIX="${PREFIX}" \
		VERSION="${DISTVERSIONFULL}" COMMIT=""
PLIST_FILES=	bin/${PORTNAME} \
		bin/${PORTNAME}-application-mapper
PLIST_DIRS=	${ETCDIR}
PORTDATA=	*
PORTDOCS=	*
PORTEXAMPLES=	*

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

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
		${WRKSRC}/examples/*.conf \
		${WRKSRC}/src/config.c \
		${WRKSRC}/src/${PORTNAME}.c
# https://lists.freebsd.org/pipermail/freebsd-x11/2019-March/023097.html
	@${REINPLACE_CMD} -e 's,__FreeBSD,&_disabled,' \
		${WRKSRC}/src/vkbd/uinput.c

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
