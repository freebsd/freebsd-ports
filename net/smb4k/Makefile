# New ports collection makefile for:	smb4k
# Date created:				28 Oct 2005
# Whom:					Rashid N. Achilov <shelton@granch.ru>
#
# $FreeBSD$
#

PORTNAME=		smb4k
PORTVERSION=		0.9.9
PORTREVISION=	2
CATEGORIES=		net kde
MASTER_SITES=		${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	smb4k

MAINTAINER=		citycat4@ngs.ru
COMMENT=		KDE 3.x SMB Network browser and SMB shares mounting center

RUN_DEPENDS=		sudo:${PORTSDIR}/security/sudo \
			smbstatus:${PORTSDIR}/net/samba3

USE_KDEBASE_VER=	3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS += 	--with-qt-dir=${QT_PREFIX} \
			--with-extra-includes=${LOCALBASE}/include \
			--with-extra-libs=${LOCALBASE}/lib
DOCSDIR=		${PREFIX}/share/doc/HTML/en/${PORTNAME}
MESSAGE=		${WRKDIR}/pkg-message

post-install:
.for i in smb2awk smb2nsmbrc
	${INSTALL_SCRIPT} ${FILESDIR}/${i} ${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${FILESDIR}/README.FreeBSD ${DOCSDIR}

	@${SED} -e "s,%%PREFIX%%,${PREFIX},g" ${PKGMESSAGE} > ${MESSAGE}
	@${CAT} ${MESSAGE}

.include <bsd.port.mk>
