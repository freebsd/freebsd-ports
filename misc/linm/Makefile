# Created by: CHOI Junho <cjh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	linm
DISTVERSION=	0.8.1-1
PORTREVISION=	5
CATEGORIES=	misc shells
MASTER_SITES=	http://kldp.net/frs/download.php/4508/
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Clone of Mdir, mc-style terminal file manager

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext pkgconfig gmake libtool ncurses ssl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-cfgpath="${ETCDIR}"
MAKE_JOBS_UNSAFE=	yes
INSTALL_TARGET=	install-strip

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	SMB DOCS
OPTIONS_SUB=	yes

SMB_CONFIGURE_ENV_OFF=	ac_cv_lib_smbclient_smbc_new_context=no
SMB_CPPFLAGS=	-I${SAMBAINCLUDES}
SMB_LIBS=	-L${SAMBALIBS}
SMB_USES=	iconv samba:lib

post-patch:
	@${REINPLACE_CMD} -e 's|configpath|cfgpath|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^AM_CFLAGS/s|=.*|= -fPIC -std=gnu89|' \
		${WRKSRC}/panel/vfs/libssh2/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in AUTHORS ChangeLog README README.ko_euckr README.ko_utf8
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
