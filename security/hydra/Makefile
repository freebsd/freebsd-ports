# ex:ts=8
# Ports collection makefile for:  hydra
# Date created:			  Tue Oct 08, 2002
# Whom:				  Laurent LEVIER (llevier@argosnet.com)
#
# $FreeBSD$
#

PORTNAME=	hydra
PORTVERSION=	6.1
CATEGORIES=	security
MASTER_SITES=	http://freeworld.thc.org/releases/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	llevier@argosnet.com
COMMENT=	Brute force attack utility working on multiple network services

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE
NO_LATEST_LINK=	yes
PLIST_FILES=	bin/hydra
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_OPENSSL=	yes
WANT_GNOME=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-src

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
.endif
.if defined(WITH_SVN)
LIB_DEPENDS+=	svn_client-1:${PORTSDIR}/devel/subversion
.endif

.if defined(WITH_X11)
USE_GNOME=	gtk20
PLIST_FILES+=	bin/xhydra
.else
CONFIGURE_ARGS+=	--disable-xhydra
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|CC = gcc||; \
		s|-O2|${CFLAGS}|; s|md4\..||g' \
		${WRKSRC}/Makefile.am

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/hydra ${PREFIX}/bin
.if defined(WITH_X11)
	@${INSTALL_PROGRAM} ${WRKSRC}/hydra-gtk/src/xhydra ${PREFIX}/bin
.endif

.include <bsd.port.post.mk>
