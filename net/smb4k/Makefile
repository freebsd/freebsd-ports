# New ports collection makefile for:	smb4k
# Date created:				28 Oct 2005
# Whom:					Rashid N. Achilov <shelton@granch.ru>
#
# $FreeBSD$
#

PORTNAME=		smb4k
PORTVERSION=		0.9.9
PORTREVISION=	7
CATEGORIES=		net kde
MASTER_SITES=		${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	smb4k

MAINTAINER=		citycat4@ngs.ru
COMMENT=		KDE 3.x SMB Network browser and SMB shares mounting center

RUN_DEPENDS=		sudo:${PORTSDIR}/security/sudo \
			smbstatus:${PORTSDIR}/${SAMBA_PORT}

SAMBA_PORT?=	net/samba34

USE_KDEBASE_VER=	3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS += 	--with-qt-dir=${QT_PREFIX} \
			--with-extra-includes=${LOCALBASE}/include \
			--with-extra-libs=${LOCALBASE}/lib
DOCSDIR=		${PREFIX}/share/doc/HTML/en/${PORTNAME}
SUB_FILES=		pkg-message

post-install:
.for i in smb2awk smb2nsmbrc
	${INSTALL_SCRIPT} ${FILESDIR}/${i} ${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${FILESDIR}/README.FreeBSD ${DOCSDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
