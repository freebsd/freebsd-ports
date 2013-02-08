# $FreeBSD$

PORTNAME=	shared-mime-info
PORTVERSION=	1.2
CATEGORIES=	misc kde
MASTER_SITES=	# none
PKGNAMEPREFIX=	kde4-
DISTNAME=	# none
EXTRACT_SUFX=	# none

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Handles shared MIME database under $${KDE4_PREFIX}

RUN_DEPENDS=	update-mime-database:${PORTSDIR}/misc/shared-mime-info

USE_KDE4=	kdeprefix kdehier

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

MIMESUBDIRS=	application audio image inode message model multipart \
		packages text video x-epoc x-content

.include <bsd.port.pre.mk>

.if ${KDE4_PREFIX} != ${LOCALBASE}
PLIST_SUB+=	HACK=""
.else
PLIST_SUB+=	HACK="@comment "
.endif

do-install:
.if ${KDE4_PREFIX} != ${LOCALBASE}
.for dir in ${MIMESUBDIRS}
	${MKDIR} ${KDE4_PREFIX}/share/mime/${dir}
	${TOUCH} ${KDE4_PREFIX}/share/mime/${dir}/.keep_me
.endfor
	@-update-mime-database ${KDE4_PREFIX}/share/mime
.else
	${DO_NADA}
.endif

.include <bsd.port.post.mk>
