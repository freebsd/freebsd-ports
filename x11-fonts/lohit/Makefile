# $FreeBSD$

PORTNAME=	Lohit
DISTVERSION=	20140220
PORTREVISION=	3
CATEGORIES=	x11-fonts
MASTER_SITES=	https://releases.pagure.org/lohit/
DISTNAME=	lohit-ttf-${PORTVERSION}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Lohit fonts

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${FONTSDIR}/Lohit-Assamese.ttf \
		${FONTSDIR}/Lohit-Bengali.ttf \
		${FONTSDIR}/Lohit-Devanagari.ttf \
		${FONTSDIR}/Lohit-Gujarati.ttf \
		${FONTSDIR}/Lohit-Kannada.ttf \
		${FONTSDIR}/Lohit-Malayalam.ttf \
		${FONTSDIR}/Lohit-Marathi.ttf \
		${FONTSDIR}/Lohit-Oriya.ttf \
		${FONTSDIR}/Lohit-Punjabi.ttf \
		${FONTSDIR}/Lohit-Tamil-Classical.ttf \
		${FONTSDIR}/Lohit-Tamil.ttf \
		${FONTSDIR}/Lohit-Telugu.ttf

SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
