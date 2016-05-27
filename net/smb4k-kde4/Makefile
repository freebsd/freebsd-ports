# Created by: Josh Paetzel <jpaetzel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	smb4k-kde4
PORTVERSION=	0.10.9
PORTREVISION=	11
CATEGORIES=	net kde
MASTER_SITES=	SF/smb4k
DISTNAME=	smb4k-${PORTVERSION}

MAINTAINER=	jpaetzel@FreeBSD.org
COMMENT=	KDE 4.x SMB Network browser and SMB shares mounting center

RUN_DEPENDS=	sudo:security/sudo \
		smbstatus:${SAMBA_PORT}

SAMBA_PORT?=	net/samba36

USES=		cmake gettext tar:bzip2
USE_LDCONFIG=	${PREFIX}/lib ${PREFIX}/lib/kde4
USE_KDE4=	kdelibs automoc4 runtime
USE_QT4=	corelib gui network opengl script svg webkit \
		qmake_build moc_build rcc_build uic_build phonon
DOCSDIR=	${PREFIX}/share/doc/HTML/en/smb4k
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
NLS=	""
.else
NLS=	"@comment "
.endif
PLIST_SUB+=	NLS=${NLS}

pre-configure:
.if ! ${PORT_OPTIONS:MNLS}
	${REINPLACE_CMD} -e 's|add_subdirectory( po )|#add_subdirectory( po )|'     \
		${WRKSRC}/CMakeLists.txt
.endif
.if ! ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e 's|add_subdirectory( doc )|#add_subdirectory( doc )|'   \
		${WRKSRC}/CMakeLists.txt
.endif

post-install:
.for i in smb2awk smb2nsmbrc
	${INSTALL_SCRIPT} ${FILESDIR}/${i} ${STAGEDIR}${PREFIX}/bin
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/README.FreeBSD ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
