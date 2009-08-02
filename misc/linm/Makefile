# New ports collection makefile for:	linm
# Date created:		24 Jan 2005
# Whom:			cjh@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	linm
PORTVERSION=	${LINM_VER}.1
PORTREVISION=	2
CATEGORIES=	misc shells
MASTER_SITES=	http://kldp.net/frs/download.php/3152/ \
		ftp://ftp.kr.freebsd.org/pub/kldp.net/download/mls/1.LinMStable/LinM${LINM_VER}/
DISTNAME=	linm_${LINM_VER}-1

MAINTAINER=	cjh@FreeBSD.org
COMMENT=	Clone of Mdir, mc-style terminal file manager

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkg-config

USE_AUTOTOOLS=	libtool:22
USE_ICONV=	yes
USE_OPENSSL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV=  CPPFLAGS=-I${LOCALBASE}/include
# does not work now
#.if defined(WITHOUT_NLS)
#CONFIGURE_ARGS+=--disable-nls
#PLIST_SUB+=	NLS="@comment "
#.else
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib -lintl -liconv"
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
#.endif

CONFIGURE_ARGS+= --enable-cfgpath="${PREFIX}/etc/linm" --enable-kolocalepath="${PREFIX}/share/locale/ko/LC_MESSAGES"

LINM_VER=	0.7.7
WRKSRC=		${WRKDIR}/linm-${LINM_VER}

post-patch:
	@${REINPLACE_CMD} -e 's|Panel::SetCur|SetCur|' ${WRKSRC}/panel/common/panel.h
	@${REINPLACE_CMD} -e 's|Position::Show|Show|' ${WRKSRC}/src/ncurses/dialog.h

post-install:
.if !defined (NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/linm
.for file in AUTHORS COPYING ChangeLog README README.ko_euckr README.ko_utf8
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
