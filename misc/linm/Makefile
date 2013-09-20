# Created by: cjh@FreeBSD.org
# $FreeBSD$

PORTNAME=	linm
DISTVERSION=	0.8.1-1
CATEGORIES=	misc shells
MASTER_SITES=	http://kldp.net/frs/download.php/4508/
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Clone of Mdir, mc-style terminal file manager

LICENSE=	GPLv2 # (or later)

OPTIONS_DEFINE=	SMB

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:C/-.*//}

USES=		gettext pkgconfig
USE_OPENSSL=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--enable-cfgpath="${ETCDIR}"
MAKE_JOBS_UNSAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSMB}
LIB_DEPENDS+=	smbclient:${PORTSDIR}/net/samba-libsmbclient
PLIST_SUB+=	SMB=""
.else
CONFIGURE_ENV+=	ac_cv_lib_smbclient_smbc_new_context=no
PLIST_SUB+=	SMB="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|configpath|cfgpath|g ; \
		 /LIBS=/s|-lpthread|-pthread|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/^AM_CFLAGS/s|=.*|= -fPIC -std=gnu89|' \
		${WRKSRC}/panel/vfs/libssh2/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in AUTHORS ChangeLog README README.ko_euckr README.ko_utf8
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${DOCSDIR})
.endfor
.endif

.include <bsd.port.mk>
