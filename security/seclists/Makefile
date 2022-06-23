PORTNAME=	seclists
DISTVERSION=	2022.2
PORTREVISION=	2
CATEGORIES=	security www

MAINTAINER=	salvadore@FreeBSD.org
COMMENT=	Collection of multiple types of lists used during security assessments

LICENSE=	GPLv2 GPLv2+ MIT
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/Discovery/Web-Content/Domino-Hunter/LICENCE
LICENSE_FILE_GPLv2+ =	${WRKSRC}/Web-Shells/laudanum-0.8/GPL
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	danielmiessler
GH_PROJECT=	SecLists

NO_ARCH=	yes
NO_BUILD=	yes

FILES_TO_BE_REMOVED=	.bin/generate-contributors \
			.bin/generate-environment-identifiers-dict.sh \
			.gitattributes \
			.github/workflows/wordlist-updater_combined_directories.yml \
			.github/workflows/wordlist-updater_combined_words.yml \
			.gitignore \
			CONTRIBUTING.md \
			CONTRIBUTORS.md \
			Discovery/Web-Content/Domino-Hunter/LICENCE \
			LICENSE \
			README.md \
			Web-Shells/laudanum-0.8/GPL

DIRS_TO_BE_REMOVED=	.bin .github/workflows .github

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	cd ${STAGEDIR}${DATADIR} && ${RM} ${FILES_TO_BE_REMOVED} && ${RMDIR} ${DIRS_TO_BE_REMOVED}

.include <bsd.port.mk>
