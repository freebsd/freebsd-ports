# New ports collection makefile for:	smb4k
# Date created:				28 Oct 2005
# Whom:					Rashid N. Achilov <shelton@granch.ru>
#
# $FreeBSD$
#

PORTNAME=		smb4k
PORTVERSION=		0.6.8
CATEGORIES=		net kde
MASTER_SITES=		http://download.berlios.de/smb4k/

MAINTAINER=		shelton@www.granch.ru
COMMENT=		KDE 3.x SMB Network browser and SMB shares mounting center

RUN_DEPENDS=		sudo:${PORTSDIR}/security/sudo \
			smbstatus:${PORTSDIR}/net/samba3

USE_KDEBASE_VER=	3
USE_GMAKE=		yes
USE_AUTOTOOLS=		libtool:15
USE_GETTEXT=		yes
CONFIGURE_ARGS += 	--with-qt-dir=${QT_PREFIX} \
			--with-extra-includes=${LOCALBASE}/include \
			--with-extra-libs=${LOCALBASE}/lib
DOCSDIR=		share/doc/HTML/en/${PORTNAME}
PLIST_SUB=		DOCSDIR=${DOCSDIR}

INSTALLS_SHLIB=		yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		does not build on 4.x (missing sys/statvfs.h)
.endif

post-install:
.for i in smb2awk smb2nsmbrc
	${INSTALL_SCRIPT} ${FILESDIR}/${i} ${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${FILESDIR}/README.FreeBSD ${PREFIX}/${DOCSDIR}
	@${SED} -e "s,%%PREFIX%%,${PREFIX},g" ${PKGMESSAGE}

.include <bsd.port.post.mk>
