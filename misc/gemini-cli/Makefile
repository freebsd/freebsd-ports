PORTNAME=	gemini-cli
DISTVERSION=	0.6.1
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Google Gemini api for terminal (CLI)
WWW=		https://google-gemini.github.io/gemini-cli/ \
		https://github.com/google-gemini/gemini-cli

LICENSE=	APACHE20

FETCH_DEPENDS=	npm:www/npm

USES=		nodejs:run

NO_BUILD=	yes
NO_ARCH=	yes

do-fetch:
	@if ! [ -f ${DISTDIR}/${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} ]; then \
		npm install --prefix ${WRKSRC} -g @google/gemini-cli@${DISTVERSION} && \
		${FIND} ${WRKDIR} -and -exec ${TOUCH} -h -d 1970-01-01T00:00:00Z {} \; && \
		cd ${WRKDIR} && ${FIND} ${PORTNAME}-${DISTVERSION} -print0 | LC_ALL=C ${SORT} -z | \
	        	${TAR} czf ${DISTDIR}/${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} --format=bsdtar --gid 0 --uid 0 --options gzip:!timestamp --no-recursion --null -T -; \
	fi

do-install:
	# install files
	@cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}
	# update
	${REINPLACE_CMD} -i '' \
		-e "s|#!/usr/bin/env node|#!${PREFIX}/bin/node|" \
		${STAGEDIR}${PREFIX}/lib/node_modules/@google/gemini-cli/dist/index.js
	# set exec bit
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/lib/node_modules/@google/gemini-cli/dist/index.js

.include <bsd.port.mk>
