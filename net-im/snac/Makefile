PORTNAME=	snac
DISTVERSION=	2.81
CATEGORIES=	net-im www
MASTER_SITES=	https://codeberg.org/grunfink/snac2/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	matthew@matthewphillips.info
COMMENT=	Simple, minimalistic ActivityPub instance written in portable C
WWW=		https://codeberg.org/grunfink/snac2

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		ssl
USE_RC_SUBR=	snac

SUB_FILES=	pkg-message \
		snac
SUB_LIST=	SNACDATADIR="${SNACDATADIR}" \
		GROUP="${GROUPS}" \
		USER="${USERS}"

SNACDATADIR=	/var/db/snac

WRKSRC=		${WRKDIR}/snac2

USERS=		snac
GROUPS=		snac

PKGMESSAGE=	${FILESDIR}/pkg-message

PLIST_FILES=	bin/snac \
		share/man/man1/snac.1.gz \
		share/man/man5/snac.5.gz \
		share/man/man8/snac.8.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/snac

.include <bsd.port.mk>
