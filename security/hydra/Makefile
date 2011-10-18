# ex:ts=8
# Ports collection makefile for:  hydra
# Date created:			  Tue Oct 08, 2002
# Whom:				  Laurent LEVIER (llevier@argosnet.com)
#
# $FreeBSD$
#

PORTNAME=	hydra
PORTVERSION=	7.1
CATEGORIES=	security
MASTER_SITES=	http://freeworld.thc.org/releases/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	cvs-src@yandex.ru
COMMENT=	Brute force attack utility working on multiple network services

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	idn:${PORTSDIR}/dns/libidn \
		pcre.0:${PORTSDIR}/devel/pcre \
		sasl2.2:${PORTSDIR}/security/cyrus-sasl2

NO_LATEST_LINK=	yes
PLIST_FILES=	bin/hydra bin/pw-inspector bin/dpl4hydra.sh
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_OPENSSL=	yes
WANT_GNOME=	yes
MAKE_JOBS_SAFE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-src

MAN1=		hydra.1 pw-inspector.1

OPTIONS=	FIREBIRD "Enable firebird support" off \
		SSH "Enable ssh support" off \
		SVN "Enable subversion support" off \
		X11 "Install xhydra" off

.include <bsd.port.pre.mk>

.if defined(WITH_FIREBIRD)
LIB_DEPENDS+=	fbclient.2:${PORTSDIR}/databases/firebird20-client
.endif
.if defined(WITH_SSH)
LIB_DEPENDS+=	ssh.4:${PORTSDIR}/security/libssh
CFLAGS+=	-I${LOCALBASE}/include
.endif
.if defined(WITH_SVN)
LIB_DEPENDS+=	svn_client-1:${PORTSDIR}/devel/subversion
.endif

.if defined(WITH_X11)
USE_GNOME=	gtk20 pkgconfig
PLIST_FILES+=	bin/xhydra
MAN1+=		xhydra.1
.else
CONFIGURE_ARGS+=	--disable-xhydra
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|CC = gcc||; \
		s|-O2|${CFLAGS}|; s|md4\..||g' \
		${WRKSRC}/Makefile.am

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/hydra ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/pw-inspector ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/dpl4hydra.sh ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/hydra.1 ${MANPREFIX}/man/man1/hydra.1
	@${INSTALL_MAN} ${WRKSRC}/pw-inspector.1 ${MANPREFIX}/man/man1/pw-inspector.1
.if defined(WITH_X11)
	@${INSTALL_PROGRAM} ${WRKSRC}/hydra-gtk/src/xhydra ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/xhydra.1 ${MANPREFIX}/man/man1/xhydra.1
.endif

.include <bsd.port.post.mk>
