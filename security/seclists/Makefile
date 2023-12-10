PORTNAME=	seclists
DISTVERSION=	2023.4
CATEGORIES=	security www

MAINTAINER=	salvadore@FreeBSD.org
COMMENT=	Collection of multiple types of lists used during security assessments
WWW=		https://github.com/danielmiessler/SecLists

LICENSE=	GPLv2 GPLv2+ MIT
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/Discovery/Web-Content/Domino-Hunter/LICENCE
LICENSE_FILE_GPLv2+ =	${WRKSRC}/Web-Shells/laudanum-1.0/GPL
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	danielmiessler
GH_PROJECT=	SecLists

NO_ARCH=	yes
NO_BUILD=	yes

FILES_TO_BE_REMOVED=	.gitattributes \
			.gitignore \
			CONTRIBUTING.md \
			CONTRIBUTORS.md \
			Discovery/Web-Content/Domino-Hunter/LICENCE \
			LICENSE \
			README.md \
			SecLists.png \
			Web-Shells/laudanum-1.0/GPL

DIRS_TO_BE_REMOVED=	.bin .github

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	cd ${STAGEDIR}${DATADIR} && ${RM} ${FILES_TO_BE_REMOVED} && ${RM} -Rf ${DIRS_TO_BE_REMOVED}

.include <bsd.port.mk>
