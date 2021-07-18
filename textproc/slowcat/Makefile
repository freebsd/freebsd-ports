PORTNAME=	slowcat
DISTVERSION=	2.2
CATEGORIES=	textproc perl5
MASTER_SITES=	http://artscene.textfiles.com/viewers/linux/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.pl
DIST_SUBDIR=	${PKGNAME}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Write output slowly, emulating physical serial terminal

LICENSE=	PD

USES=		perl5

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/${DISTNAME}

do-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME}${EXTRACT_SUFX} \
		${STAGEDIR}${PREFIX}/bin/${DISTNAME}

.include <bsd.port.mk>
