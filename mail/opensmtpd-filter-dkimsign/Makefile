PORTNAME=	filter-dkimsign
DISTVERSION=	0.5
CATEGORIES=	mail
MASTER_SITES=	https://imperialat.at/releases/
PKGNAMEPREFIX=	opensmtpd-

MAINTAINER=	mvalleton@seos.fr
COMMENT=	Library for writing opensmtpd filters
WWW=		https://imperialat.at/dev/filter-dkimsign/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libevent.so:devel/libevent \
		libopensmtpd.so:mail/libopensmtpd

MAKEFILE=	Makefile.gnu
USES=		gmake localbase ssl
PLIST_FILES=	libexec/opensmtpd/filter-dkimsign \
		share/man/man8/filter-dkimsign.8.gz

# LDFLAGS used by gmake during build
# MANDIR and BINDIR used by make during install
MAKE_ARGS=	BINDIR=${LOCALBASE}/libexec/opensmtpd \
		MANDIR=${LOCALBASE}/share/man/man \
		MK_DEBUG_FILES=no

# Makefile.gnu's install target uses Linux-specific install options so we
# have to use the OpenBSD Makefile instead. Thus, it's easier to just do
# it manually.
do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/opensmtpd
	${INSTALL_PROGRAM} ${WRKSRC}/filter-dkimsign ${STAGEDIR}${PREFIX}/libexec/opensmtpd/
	${INSTALL_MAN} ${WRKSRC}/filter-dkimsign.8.gz ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
