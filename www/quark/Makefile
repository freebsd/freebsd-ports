PORTNAME=	quark
DISTVERSION=	g20190923
PORTREVISION=	1
CATEGORIES=	www
# XXX: See PR 244457 for details why this is not LOCAL/0mp.
MASTER_SITES=	https://people.freebsd.org/~0mp/distfiles/
PKGNAMESUFFIX=	-server
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSIONFULL}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small and simple HTTP GET/HEAD-only web server for static content

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS_INSTALL=	quark

MAKE_ARGS=	MANPREFIX=${PREFIX}/share/man

PLIST_FILES=	bin/quark \
		share/man/man1/quark.1.gz

.include <bsd.port.options.mk>

# _WITH_DPRINTF support was removed precisely in r303524.
.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1200002
CFLAGS+=	-D_WITH_DPRINTF
.endif

_COMMIT_HASH=	3c7049e9063edebbd1934178f263f9f3c9b8ddf5

pre-everything::
	@${ECHO_MSG} "You can build quark with your own config.h using the QUARK_CONF knob:"
	@${ECHO_MSG} "make QUARK_CONF=/path/to/quark/config.h install clean"

post-patch:
.if defined(QUARK_CONF)
	@${ECHO_MSG} "Creating config.h from ${QUARK_CONF}"
	@${LN} -sf ${QUARK_CONF} ${WRKSRC}/config.h
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/quark

.include <bsd.port.mk>
