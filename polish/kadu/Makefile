# Ports collection makefile for:   kadu
# Date created:        17 July 2003
# Whom:                Jacek Pelka <jacek@combit.com.pl>
#
# $FreeBSD$
#

PORTNAME=		kadu
PORTVERSION=		0.4.3
PORTEPOCH=		1
CATEGORIES=		polish net-im
MASTER_SITES=		http://www.kadu.net/download/stable/
DISTNAME=		${PORTNAME}-${PORTVERSION}

MAINTAINER=		mwisnicki+freebsd@gmail.com
COMMENT=		QT Gadu-Gadu client

LIB_DEPENDS=		gadu.3:${PORTSDIR}/polish/ekg\
			sndfile.1:${PORTSDIR}/audio/libsndfile

USE_BZIP2=		yes
USE_GMAKE=		yes
USE_OPENSSL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-existing-libgadu="${LOCALBASE}" \
			--with-includes="${LOCALBASE}/include ${X11BASE}/include" \
			--with-libs="${LOCALBASE}/lib ${X11BASE}/lib" \
			--program-transform-name=''
CONFIGURE_ENV=		QTDIR="${QT_PREFIX}"

USE_QT_VER=		3
QT_NONSTANDARD=		yes

WRKSRC=			${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
post-patch:
	@${ECHO} "MODULE_LDFLAGS=\"-lcrypto\"" >> ${WRKSRC}/modules/encryption/spec
.endif

post-install:
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/kadu/kadu.desktop ${PREFIX}/share/applications

.include <bsd.port.post.mk>
