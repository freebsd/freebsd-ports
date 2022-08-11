PORTNAME=	flawfinder
PORTVERSION=	2.0.19
CATEGORIES=	security devel
MASTER_SITES=	http://www.dwheeler.com/flawfinder/ \
		PACKETSTORM/UNIX/security

MAINTAINER=	se@FreeBSD.org
COMMENT=	Examines source code looking for security weaknesses

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python shebangfix
SHEBANG_FILES=	flawfinder.py
NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/flawfinder man/man1/flawfinder.1.gz
PORTDOCS=	ChangeLog README.md flawfinder.pdf flawfinder.ps
PORTEXAMPLES=	correct-results-004.txt correct-results-005.txt \
		correct-results-006.txt correct-results-008.txt \
		correct-results.csv correct-results.html correct-results.txt \
		makefile no-ending-newline.c test-boost-system.hpp \
		test-cpp-digit-separator.c test-cpp-digit-separator.cpp \
		test-diff-005.patch test-junk-006.txt test-junk-008.txt \
		test-patched.c test-results-004.txt test-results-005.txt \
		test-results-006.txt test-results-008.txt test-results.csv \
		test-results.html test-results.txt test-saved-hitlist-006.txt \
		test-saved-hitlist-008.txt test.c test2.c

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/flawfinder.py ${STAGEDIR}${PREFIX}/bin/flawfinder
	${INSTALL_MAN} ${WRKSRC}/flawfinder.1 ${STAGEDIR}${MANPREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	for f in ${PORTEXAMPLES}; do \
		${INSTALL_DATA} ${WRKSRC}/test/$$f ${STAGEDIR}${EXAMPLESDIR}; \
	done

.include <bsd.port.mk>
