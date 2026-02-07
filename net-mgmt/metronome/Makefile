PORTNAME=	metronome
DISTVERSION=	0.9.0
PORTREVISION=	26
CATEGORIES=	net-mgmt dns

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Client-side java script to render graphs w/o depending on graphite
WWW=		https://github.com/ahupowerdns/metronome

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

USES=		autoreconf:build compiler:c++11-lang eigen:3 libtool:build \
		localbase:ldflags pathfix pkgconfig
USE_CXXSTD=	c++14
USE_GITHUB=	yes
GH_ACCOUNT=	ahupowerdns
USE_LDCONFIG=	yes
USE_RC_SUBR=	metronome

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

SUB_FILES=	pkg-message
SUB_LIST+=	METRONOME_DBDIR=${METRONOME_DBDIR} \
		METRONOME_USER=${METRONOME_USER}

METRONOME_USER?=	_metronome
USERS=			${METRONOME_USER}
GROUPS=			${METRONOME_USER}

PLIST_SUB+=	METRONOME_DBDIR=${METRONOME_DBDIR} \
		METRONOME_USER=${METRONOME_USER}
OPTIONS_DEFINE=	DOCS

METRONOME_DBDIR?=	/var/db/metronome

pre-configure:
	(cd ${WRKSRC}; ./bootstrap )

post-install:
	${MKDIR} ${STAGEDIR}${METRONOME_DBDIR}

.include <bsd.port.mk>
