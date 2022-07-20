PORTNAME=	mrouted
PORTVERSION=	3.9.8
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Multicast routing daemon providing DVMRP for IPv4

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe
CPE_VENDOR=	troglobit
USE_GITHUB=	yes
GH_ACCOUNT=	troglobit
USE_RC_SUBR=	mrouted
HAS_CONFIGURE=	yes
MAKE_ARGS=	sysconfdir="${PREFIX}/etc" \
		mandir="${MAN8PREFIX}/man/man8"
PORTDOCS=	README AUTHORS ChangeLog
PLIST_FILES=	sbin/map-mbone sbin/mrouted sbin/mrinfo sbin/mtrace \
		etc/mrouted.conf man/man8/map-mbone.8.gz \
		man/man8/mrinfo.8.gz man/man8/mrouted.8.gz \
		man/man8/mtrace.8.gz

OPTIONS_DEFINE=	DOCS
DOCS_MAKE_ARGS=	datadir="${DOCSDIR}" doc=yes

.include <bsd.port.mk>
