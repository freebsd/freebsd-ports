PORTNAME=	gimp-help
DISTVERSION=	3.0.0
CATEGORIES=	misc graphics
MASTER_SITES=	https://kojipkgs.fedoraproject.org/packages/gimp-help/${DISTVERSION}/1.fc43/noarch/
PKGNAMESUFFIX=	-en
DISTNAME=	${PORTNAME}-${DISTVERSION}-1.fc43.noarch
EXTRACT_SUFX=	.rpm

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GIMP User Manual in English
WWW=		https://docs.gimp.org/

LICENSE=	GFDL

EXTRACT_AFTER_ARGS=	--strip-components 7 \
			--no-same-owner --no-same-permissions

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DATADIR=	${DOCSDIR}
PORTDATA=	*

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/en
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/en)

.include <bsd.port.mk>
