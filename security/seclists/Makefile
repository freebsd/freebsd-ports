PORTNAME=	seclists
DISTVERSION=	2022.2
CATEGORIES=	security www

MAINTAINER=	salvadore@FreeBSD.org
COMMENT=	Collection of multiple types of lists used during security assessments

LICENSE=	GPLv2 GPLv2+ MIT
LICENSE_COMB=	multi
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
#
# The following is necessary because of a too long filename for pkg to work properly.
# The error reported is:
#
# pkg-static: Fail to create temporary file: /usr/local/share/seclists/Payloads/File-Names/max-length/.pkgtemp.AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA.php.gif.E8InfduP3cVP:File name too long
#
# The following commit should fix the issue with pkg:
#
# https://github.com/freebsd/pkg/commit/ce75303c613f2f5d04fdd7c9edd6f4cd40eb9dac
#
# The workaround should be removed once pkg has been updated to a version
# including this commit (remember to also remove pkg-message).
#
	cd ${STAGEDIR}${DATADIR} && ${MV} Payloads/File-Names/max-length/AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA.php.gif Payloads/File-Names/max-length/232A.php.gif

.include <bsd.port.mk>
