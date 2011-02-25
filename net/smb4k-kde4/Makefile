# New ports collection makefile for:	smb4k-kde4
# Date created:				02 Jan 2011
# Whom:					Josh Paetzel <jpaetzel@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		smb4k-kde4
PORTVERSION=		0.10.9
PORTREVISION=	5
CATEGORIES=		net kde
MASTER_SITES=		${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	smb4k
DISTNAME=		smb4k-${PORTVERSION}

MAINTAINER=		jpaetzel@FreeBSD.org
COMMENT=		KDE 4.x SMB Network browser and SMB shares mounting center

RUN_DEPENDS=		sudo:${PORTSDIR}/security/sudo \
			smbstatus:${PORTSDIR}/${SAMBA_PORT}

SAMBA_PORT?=	net/samba34

USE_CMAKE=	yes
USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	${PREFIX}/lib ${PREFIX}/lib/kde4
INSTALLS_ICONS=	yes
USE_KDE4=	kdehier kdeprefix kdelibs automoc4 runtime
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui network opengl script svg webkit \
		qmake_build moc_build rcc_build uic_build phonon
DOCSDIR=	${PREFIX}/share/doc/HTML/en/smb4k
SUB_FILES=	pkg-message

.if defined(WITHOUT_NLS)
NLS=	"@comment "
.else
NLS=	""
.endif
PLIST_SUB+=	NLS=${NLS}

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+= ${LOCALBASE}/share/xml/docbook/4.2/docbookx.dtd:${PORTSDIR}/textproc/docbook-xml
.endif

pre-configure:
.if defined(WITHOUT_NLS)
	${REINPLACE_CMD} -e 's|add_subdirectory( po )|#add_subdirectory( po )|'     \
		${WRKSRC}/CMakeLists.txt
.endif
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e 's|add_subdirectory( doc )|#add_subdirectory( doc )|'   \
		${WRKSRC}/CMakeLists.txt
.endif

post-install:
.for i in smb2awk smb2nsmbrc
	${INSTALL_SCRIPT} ${FILESDIR}/${i} ${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${FILESDIR}/README.FreeBSD ${DOCSDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
